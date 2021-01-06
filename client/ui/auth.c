#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <ctype.h>
#include "signin.c"
#include "signup.c"
GtkWidget	*window;
GtkWidget	*fixed,*fixed1;
GtkWidget	*signIn,*signIn1,*testclick;
GtkWidget	*signUp; 
GtkWidget	*SignUpFixed, *SignUpTitle,*SignUpBtn,*NewSignUpLogin,*NewSignUpPassword1,*SignUpViewPort,*SignUpView,*SignUpViewPort1,*SignUpView1;
GtkWidget	*saveBtn,*SignInLogin,*SignInLoginViewPort,*SignInLoginView;
GtkBuilder	*builder;
GtkWidget	*testfuck;

void	on_signIn1_clicked(GtkButton *b);
void	on_signUp_clicked(GtkButton *b);
void	submit_signup (GtkButton *b);

// void	on_changed_textSignUp2(GtkTextBuffer *t);
int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("auth.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_builder_connect_signals(builder, NULL);
	
	SignUpFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpFixed"));
	SignUpTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpTitle"));
	// first input login 
    SignUpViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpViewPort"));
    SignUpView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpView"));
	//second input password
	NewSignUpPassword1 = GTK_WIDGET(gtk_builder_get_object(builder, "NewSignUpPassword1"));
    SignUpViewPort1 = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpViewPort1"));
    SignUpView1 = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpView1"));


	// SignInWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignInWindow"));
	//button
	SignUpBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpBtn"));

	testclick = GTK_WIDGET(gtk_builder_get_object(builder, "testclick"));
	testfuck = GTK_WIDGET(gtk_builder_get_object(builder, "testfuck"));

	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
	signIn1 = GTK_WIDGET(gtk_builder_get_object(builder, "signIn1"));
    signUp = GTK_WIDGET(gtk_builder_get_object(builder, "signUp"));
    // stack1 = GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));
	
	// gtk_widget_hide(saveBtn);

	gtk_widget_show(window);
	gtk_main(); 

	return EXIT_SUCCESS;

}

void	on_signIn1_clicked (GtkButton *b) {
	printf("Sign In tapped\n");
	gtk_widget_hide(window);
	main2();
	
}

void	on_signUp_clicked (GtkButton *b) {
	printf("Sign Up tapped\n");
	main3();
	gtk_widget_hide(window);
}
void	on_saveBtn_clicked (GtkButton *b) {
	printf("Button clickedIn\n");

	
}

void	submit_signup (GtkButton *b) {
	printf("Button clickedSignUp\n");
}
void testclick_clicked (GtkButton *b){
	printf("Button clickedSignUp\n");
}
void on_testfuck_activate (GtkButton *b) {
	printf("*** SignIn tapped\n");

}