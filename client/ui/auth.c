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



// -----Sign Up-----
GtkWidget	*SignUpWindow;
GtkWidget	*SignUpFixed;
GtkWidget	*SignUpTitle;
GtkWidget	*SignUpLogin;
GtkWidget	*SignUpPassword;
GtkWidget	*SignUpName;
GtkWidget	*SignUpDateOfBirth;
GtkWidget	*SignUpPhoneNumber;
GtkWidget	*SignUpAddress;
GtkWidget	*SignUpPasswordSerialNumber,*SignUpBtnsave;


GtkWidget	*SignUpLoginViewPort,*SignUpLoginView;

GtkWidget	*SignUpNameViewPort,*SignUpNameView;

GtkWidget	*SignUpPasswordViewPort,*SignUpPasswordView;

GtkWidget	*SignUpAddressViewPort,*SignUpAddressView;
GtkWidget	*SignUpDateOfBirthViewPort,*SignUpDateOfBirthView;

GtkWidget	*SignUpPhoneNumberViewPort,*SignUpPhoneNumberView;

GtkWidget	*SignUpPasswordSerialNumberViewPort,*SignUpPasswordSerialNumberView;

// buffers
GtkTextBuffer	*SignUpNameBuffer;
GtkTextBuffer	*SignUpDateOfBirthdBuffer;
GtkTextBuffer	*SignUpAddressBuffer;
GtkTextBuffer	*SignUpPhoneNumberBuffer;
GtkTextBuffer	*SignUpPasswordSerialNumberBuffer;
GtkTextBuffer	*SignUpLoginBuffer;
GtkTextBuffer	*SignUpPasswordBuffer;
// -----Sign Up------





void	on_signIn1_clicked(GtkButton *b);
void	on_signUp_clicked(GtkButton *b);

// ----Sign in voids----
void on_changed_signinlogin(GtkTextBuffer *t);
void on_changed_signinPassword(GtkTextBuffer *t);
void	on_signInBtnSave_clicked (GtkButton *b);
// ----Sign in voids----

// ----Sign up voids----
void submit_signup(GtkButton *b);
void on_changed_signUpName(GtkTextBuffer *t);
void on_changed_signUpDateOfBirth(GtkTextBuffer *t);
void on_changed_signUpAddress(GtkTextBuffer *t);
void on_changed_signUpPasswordSerialNumber(GtkTextBuffer *t);
void on_changed_signUpLogin(GtkTextBuffer *t);
void on_changed_signUpPassword(GtkTextBuffer *t);
void on_changed_signUpPhoneNumber(GtkTextBuffer *t);
// ----Sign up voids----

// void	on_changed_textSignUp2(GtkTextBuffer *t);
int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("auth.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_builder_connect_signals(builder, NULL);
	
	//auth buttons
	fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
	signIn1 = GTK_WIDGET(gtk_builder_get_object(builder, "signIn1"));
    signUp = GTK_WIDGET(gtk_builder_get_object(builder, "signUp"));
 
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




	//Sign up elements****
	SignUpWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpWindow"));
	SignUpFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpFixed"));
	SignUpTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpTitle"));

	SignUpLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpLogin"));
	SignUpLoginViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpLoginViewPort"));
	SignUpLoginView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpLoginView"));

	SignUpName = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpName"));
	SignUpNameViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpNameViewPort"));
	SignUpNameView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpNameView"));


	SignUpBtnsave = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpBtnsave"));

	SignUpPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPassword"));
	SignUpPasswordViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPasswordViewPort"));
	SignUpPasswordView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPasswordView"));

	SignUpAddress = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpName"));
	SignUpAddressViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpAddressViewPort"));
	SignUpAddressView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpAddressView"));

	SignUpDateOfBirth = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpDateOfBirth"));
	SignUpDateOfBirthViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpDateOfBirthViewPort"));
	SignUpDateOfBirthView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpDateOfBirthView"));


	SignUpPhoneNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPhoneNumber"));
	SignUpPhoneNumberViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPhoneNumberViewPort"));
	SignUpPhoneNumberView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPhoneNumberView"));


	SignUpPasswordSerialNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPasswordSerialNumber"));
	SignUpPasswordSerialNumberViewPort = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPasswordSerialNumberViewPort"));
	SignUpPasswordSerialNumberView = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPasswordSerialNumberView"));



	// buffers
	SignUpNameBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpNameView));
	SignUpDateOfBirthdBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpDateOfBirthView));
	SignUpAddressBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpAddressView));
	SignUpPasswordBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpPasswordView));
	SignUpPhoneNumberBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpPhoneNumberView));
	SignUpPasswordSerialNumberBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpPasswordSerialNumberView));
	SignUpLoginBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpLoginView));



	// connects
	g_signal_connect(SignUpNameBuffer, "changed", G_CALLBACK(on_changed_signUpName), NULL); 
	g_signal_connect(SignUpDateOfBirthdBuffer, "changed", G_CALLBACK(on_changed_signUpDateOfBirth), NULL); 
	g_signal_connect(SignUpAddressBuffer, "changed", G_CALLBACK(on_changed_signUpAddress), NULL); 
	g_signal_connect(SignUpPasswordBuffer, "changed", G_CALLBACK(on_changed_signUpPassword), NULL); 
	g_signal_connect(SignUpPhoneNumberBuffer, "changed", G_CALLBACK(on_changed_signUpPhoneNumber), NULL); 
	g_signal_connect(SignUpPasswordSerialNumberBuffer, "changed", G_CALLBACK(on_changed_signUpPasswordSerialNumber), NULL); 
	g_signal_connect(SignUpLoginBuffer, "changed", G_CALLBACK(on_changed_signUpLogin), NULL); 
	//Sign up elements****

	gtk_widget_show(window);
	gtk_main(); 

	return EXIT_SUCCESS;

}

void	on_signIn1_clicked (GtkButton *b) {
	printf("Sign In\n");
	gtk_widget_show(SignInWindow);
	gtk_widget_hide(window);
}

void	on_signUp_clicked (GtkButton *b) {
	printf("Sign Up\n");
	gtk_widget_show(SignUpWindow);
	gtk_widget_hide(window);
}
//Sign in Voids****
void on_signInBtnSave_clicked (GtkButton *b){
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


//Sign up Voids*****
void on_SignUpBtnsave_clicked(GtkTextBuffer *t){
	printf("* SignUp clicked\n");
	printf("*** SignIn tapped\n");
	GtkTextIter begin, end;
	gchar * text;

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpNameBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpNameBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignUpNameBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpDateOfBirthdBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpDateOfBirthdBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignUpDateOfBirthdBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpAddressBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpAddressBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignUpAddressBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);



	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpPasswordSerialNumberBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpPasswordSerialNumberBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignUpPasswordSerialNumberBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpPhoneNumberBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpPhoneNumberBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignUpPhoneNumberBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);

	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpLoginBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpLoginBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignUpLoginBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpPasswordBuffer), &begin, (gint) 0);
	gtk_text_buffer_get_iter_at_offset (GTK_TEXT_BUFFER(SignUpPasswordBuffer), &end, (gint) -1);

	text = gtk_text_buffer_get_text (GTK_TEXT_BUFFER(SignUpPasswordBuffer), &begin, &end, TRUE);
	printf("-------\n%s\n-------\n", text);
}
void on_changed_signUpName(GtkTextBuffer *t){
	printf("*** Name changed\n");
}
void on_changed_signUpDateOfBirth(GtkTextBuffer *t){
	printf("*** Date of Birth changed\n");
}
void on_changed_signUpAddress(GtkTextBuffer *t){
	printf("*** Address changed\n");
}
void on_changed_signUpPassword(GtkTextBuffer *t){
	printf("*** Password changed\n");
}
void on_changed_signUpPhoneNumber(GtkTextBuffer *t){
	printf("*** Phone Number changed\n");
}
void on_changed_signUpPasswordSerialNumber(GtkTextBuffer *t){
	printf("*** Password Serial Number changed\n");
}
void on_changed_signUpLogin(GtkTextBuffer *t){
	printf("*** Login changed\n");
}
//Sign up Voids*****