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


GtkBuilder	*builder;

void on_changed_signinlogin(GtkTextBuffer *t);
void on_changed_signinPassword(GtkTextBuffer *t);
void	on_signInBtnSave_clicked (GtkButton *b);

int main2() {
	// gtk_init(NULL,NULL);
	// elements
	
	builder = gtk_builder_new_from_file ("auth.glade");

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


	


	gtk_widget_show(SignInWindow);

	gtk_main(); 

	return EXIT_SUCCESS;
}
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
