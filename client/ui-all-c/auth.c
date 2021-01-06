#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <ctype.h>
GtkWidget	*window;
GtkWidget	*fixed,*fixed1;
GtkWidget	*signIn,*signIn1;
GtkWidget	*signUp; 
GtkWidget	*SignUpFixed, *SignUpTitle,*NewSignUpLogin,*NewSignUpPassword1,*SignUpViewPort,*SignUpView,*SignUpViewPort1,*SignUpView1;
GtkWidget	*saveBtn,*SignInLogin,*SignInLoginViewPort,*SignInLoginView;
GtkBuilder	*builder;
// -----Sign In-----
GtkWidget	*SignInWindow;
GtkWidget	*SignInFixed;
GtkWidget	*SignInTitle;
GtkWidget	*SignInPassword;
GtkWidget	*signInBtnSave;

// Login
GtkWidget	*SignInLogin,*SignInLoginViewPort,*SignInLoginView;
// Password
GtkWidget	*SignInPassword,*SignInPasswordViewPort,*SignInPasswordView;
// buffers
GtkTextBuffer	*SignInLoginBuffer;
GtkTextBuffer	*SignInPasswordBuffer;
// -----Sign in------

void	on_signIn1_clicked(GtkButton *b);
void	on_signUp_clicked(GtkButton *b);

// ----Sign in voids----
void on_changed_signinlogin(GtkTextBuffer *t);
void on_changed_signinPassword(GtkTextBuffer *t);
void	on_signInBtnSave_clicked (GtkButton *b);
// ----Sign in voids----

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


	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
	signIn1 = GTK_WIDGET(gtk_builder_get_object(builder, "signIn1"));
    signUp = GTK_WIDGET(gtk_builder_get_object(builder, "signUp"));
    // stack1 = GTK_WIDGET(gtk_builder_get_object(builder, "stack1"));
	
	// gtk_widget_hide(saveBtn);


	// Sign in elements *******
	SignInWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignInWindow"));

	SignInFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignInFixed"));
	
	SignInTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignInTitle"));

	// Login input
	SignInLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignInLogin"));
	SignInLoginViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignInLoginViewPort"));
	SignInLoginView = GTK_WIDGET(gtk_builder_get_object(builder, "SignInLoginView"));


	// Password input
	SignInPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignInPassword"));
	SignInPasswordViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignInPasswordViewPort"));
	SignInPasswordView = GTK_WIDGET(gtk_builder_get_object(builder, "SignInPasswordView"));

	signInBtnSave = GTK_WIDGET(gtk_builder_get_object(builder, "signInBtnSave"));


	// buffers
	SignInLoginBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignInLoginView));
	SignInPasswordBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignInPasswordView));


	// connects
	g_signal_connect(SignInLoginBuffer, "changed", G_CALLBACK(on_changed_signinlogin), NULL); 
	g_signal_connect(SignInPasswordBuffer, "changed", G_CALLBACK(on_changed_signinPassword), NULL); 
	// Sign in elements *******

	gtk_widget_show(window);
	gtk_main(); 

	return EXIT_SUCCESS;

}

void	on_signIn1_clicked (GtkButton *b) {
	printf("Sign In tapped\n");
	gtk_widget_show(SignInWindow);
	gtk_widget_hide(window);
	
	
}

void	on_signUp_clicked (GtkButton *b) {
	printf("Sign Up tapped\n");
	// main3();
	// gtk_widget_hide(window);
}
//Sign in Voids****
void	on_signInBtnSave_clicked (GtkButton *b){
	printf("*** SignIn tapped\n");
	GtkTextIter begin, end;
	gchar * text;

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignInLoginBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignInLoginBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignInLoginBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignInPasswordBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignInPasswordBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignInPasswordBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

}
void on_changed_signinlogin(GtkTextBuffer *t) {
	printf("*** Login changed\n");
}
void on_changed_signinPassword(GtkTextBuffer *t) {
	printf("*** Password changed\n");
}
// Sign in Voids****