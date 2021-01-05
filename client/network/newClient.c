#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <ctype.h>


GtkWidget	*window,*SignUpWindow,*SignInWindow,*newSignInWindow;
GtkWidget	*fixed,*fixed1;
GtkWidget	*signIn;
GtkWidget	*signUp; 
GtkWidget	*SignUpFixed,*SignUpTitle,*SignUpLogin,*SignUpPassword,*SignUpName,*SignUpSerialNumber,*SignUpBtn;
GtkWidget	*SignInFixed,*SignInTitle,*SignInLogin,*SignInPassword,*SignInBtn;
GtkWidget	*stack1;
GtkWidget	*viewPort1;
GtkWidget	*textView1;
GtkWidget	*stack2;
GtkWidget	*viewPort2;
GtkWidget	*textView2;
GtkWidget	*saveBtn;
GtkTextBuffer	*textBuffer1;
GtkTextBuffer	*textBuffer2; 
GtkBuilder	*builder;

void on_changed_text1(GtkTextBuffer *t);
void on_changed_text2(GtkTextBuffer *t);

int clientSocket, ret;

#define PORT 8000

int main(int argc , char *argv[]){
    gtk_init(&argc, &argv);

	
	struct sockaddr_in serverAddr;
	char buffer[1024];
    char server[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}

	printf("[+]Connected to Server.\n");

    builder = gtk_builder_new_from_file ("auth.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    SignUpWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpWindow"));
	SignInWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignInWindow"));
	newSignInWindow = GTK_WIDGET(gtk_builder_get_object(builder, "newSignInWindow"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_builder_connect_signals(builder, NULL);
	
	SignUpFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpFixed"));
	SignUpTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpTitle"));
	SignUpLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpLogin"));
	SignUpPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPassword"));
	SignUpName = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpName"));
	SignUpSerialNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpSerialNumber"));
	SignUpBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpBtn"));

	SignInFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignInFixed"));
	SignInTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignInTitle"));
	SignInLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignInLogin"));
	SignInPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignInPassword"));
	SignInBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignInBtn"));
	

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
	
	signIn = GTK_WIDGET(gtk_builder_get_object(builder, "signIn"));
    signUp = GTK_WIDGET(gtk_builder_get_object(builder, "signUp"));
    stack1 = GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));

	viewPort1 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort1"));

	textView1 = GTK_WIDGET(gtk_builder_get_object(builder, "textView1"));

	stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));

	viewPort2 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort2"));

	textView2 = GTK_WIDGET(gtk_builder_get_object(builder, "textView2"));

	saveBtn = GTK_WIDGET(gtk_builder_get_object(builder, "saveBtn"));

	textBuffer1 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView1));

	textBuffer2 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView2));

	g_signal_connect(textBuffer1, "changed", G_CALLBACK(on_changed_text1), NULL); 

	g_signal_connect(textBuffer2, "changed", G_CALLBACK(on_changed_text2), NULL); 

	gtk_widget_hide(saveBtn);
	gtk_widget_show(window);
	
	gtk_main(); 


	while(1){
		// printf("Client: \t");
		// scanf("%s", &buffer[0]);
		// send(clientSocket, buffer, strlen(buffer), 0);
		// bzero(buffer, sizeof(buffer));
		// bzero(server, sizeof(server));
        // on_saveBtn_clicked (GtkButton *b, clientSocket)
		if(strcmp(buffer, ":exit") == 0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}

		if(recv(clientSocket, server, 1024, 0) < 0){
			printf("[-]Error in receiving data.\n");
		}else{
			printf("Server: \t%s\n", server);
		}
	}

	return 0;
}

void on_signIn_clicked (GtkButton *b) {
	printf("Sign In tapped\n");
	gtk_widget_hide(window);
	gtk_widget_show(newSignInWindow);
}

void on_signUp_clicked (GtkButton *b) {
	printf("Sign Up tapped\n");
	gtk_widget_hide(window);
	gtk_widget_show(SignUpWindow);
}
void on_saveBtn_clicked (GtkButton *b) {
	printf("Button clicked\n");

	GtkTextIter begin, end;
	gchar * login;
    gchar * pass;
    char * result[1024];

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer1), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer1), &end, (gint) -1);

	login = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(textBuffer1), &begin, &end, TRUE);


	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer2), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(textBuffer2), &end, (gint) -1);

	pass = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(textBuffer2), &begin, &end, TRUE);

    // result = strcat(login, ":");
    // result = strcat(result, pass);

    sprintf(result, "1:%s:%s", login, pass);
	// printf("-------\n%s\n-------\n", text);
    send(clientSocket, result, strlen(result), 0);

    bzero(result, sizeof(result));
	// gtk_widget_hide(saveBtn);
}

void on_changed_text1(GtkTextBuffer *t) {
	printf("*** Login changed\n");
	gtk_widget_show(saveBtn);
}

void on_changed_text2(GtkTextBuffer *t) {
	printf("*** Password changed\n");
	gtk_widget_show(saveBtn);
}

