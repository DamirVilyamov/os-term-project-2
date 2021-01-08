#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <mysql.h>

#define PORT 8000
//dont forget to change server ip when connecting to another network
void finish_with_error(MYSQL *con, int position)
{
    fprintf(stderr, "%s\n position:%d", mysql_error(con), position);
    mysql_close(con);
    exit(1);
}

void runQuery(char *query, MYSQL *con)
{
    if (mysql_query(con, query))
    {
        finish_with_error(con, 44);
    }
}

struct st_mysql *connectDB()
{
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "password", "testdbProd", 0, NULL, 0) == NULL)
    {
        finish_with_error(con, 20);
    }

    return con;
}

void disconnectDB(MYSQL *con)
{
    mysql_close(con);
}

int isUserAuthorized(char *login, char *password)
{
    MYSQL *con = connectDB();

    char query[100];
    sprintf(query, "SELECT * FROM users WHERE users.login = '%s' AND users.password = '%s'", login, password);

    runQuery(query, con);

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con, 51);
    }

    int num_fields = mysql_num_fields(result);
    printf("%d\n", num_fields);
    MYSQL_ROW row = mysql_fetch_row(result);
    if (!row)
    {

        return 0;
    }


    mysql_free_result(result);
    disconnectDB(con);
    return 1;
}

int main(){

	int sockfd, ret;
	struct sockaddr_in serverAddr;
    char server[1024];

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//write here server ip like 192.168.1.108

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", htons(PORT));

	if(listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}


	while(1){
		int c = sizeof(struct sockaddr_in);
		newSocket = accept(sockfd, (struct sockaddr *)&newAddr, (socklen_t*)&c);
		//newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			printf("socket<0");
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0){
			close(sockfd);
			while(1){
				recv(newSocket, buffer, 1024, 0);
                printf("Client: %s\n", buffer);
                char *action = strtok(buffer, ":");
                    if (*action ==  '1'){
                        char *login = strtok(NULL, ":");
                        char *pass = strtok(NULL, ":");
                        int answer = isUserAuthorized(login, pass);
                        printf("\nis authorised = %d", answer);
                    }
                    
				// int answer = isUserAuthorized(buffer);
				// printf("\nis authorised = %d", answer);
				if(strcmp(buffer, ":exit") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					printf("Client: %s\n", buffer);
                    scanf("%s",&server[0]);
					send(newSocket, server, strlen(server), 0);
					bzero(server, sizeof(server));
                    bzero(buffer, sizeof(buffer));
				}
			}
		}

	}

	close(newSocket);

	return 0;
};




