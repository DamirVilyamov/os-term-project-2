GtkWidget	*SignUpWindow;
GtkWidget	*SignUpFixed;
GtkWidget	*SignUpTitle;
GtkWidget	*SignUpLogin;
GtkWidget	*SignUpPassword;
GtkWidget	*SignUpName,*SignUpBtn;
GtkWidget	*SignUpDateOfBirth;
GtkWidget	*SignUpPhoneNumber;
GtkWidget	*SignUpPasswordSerialNumber;
// GtkTextBuffer	*textBuffer1;
// GtkTextBuffer	*textBuffer2,*textBufferSignUp1,*textBufferSignUp2;


// GtkWidget	*stack1;
// GtkWidget	*viewPort1;
// GtkWidget	*textView1;
// GtkWidget	*stack2;
// GtkWidget	*viewPort2;
// GtkWidget	*textView2;


GtkBuilder	*builder;


// void	on_changed_text1(GtkTextBuffer *t);
// void	on_changed_text2(GtkTextBuffer *t); 
int main3() {
	// gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("auth.glade");

	SignUpWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpWindow"));

	SignUpFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpFixed"));
	
	SignUpTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpTitle"));
	SignUpLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpLogin"));

	SignUpBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpBtn"));

	SignUpPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPassword"));	

	
	SignUpName = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpName"));

	SignUpDateOfBirth = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpDateOfBirth"));

	SignUpPhoneNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPhoneNumber"));

	SignUpPasswordSerialNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPasswordSerialNumber"));

// viewPort1 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort1"));
// 	textView1 = GTK_WIDGET(gtk_builder_get_object(builder, "textView1"));
// 	stack2 = GTK_WIDGET(gtk_builder_get_object(builder, "stack2"));
// 	viewPort2 = GTK_WIDGET(gtk_builder_get_object(builder, "viewPort2"));
// 	textView2 = GTK_WIDGET(gtk_builder_get_object(builder, "textView2"));
// 	saveBtn = GTK_WIDGET(gtk_builder_get_object(builder, "saveBtn"));
// 	textBuffer1 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView1));
// 	textBuffer2 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(textView2));
// 	textBufferSignUp1 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpView));
// 	textBufferSignUp2 = gtk_text_view_get_buffer (GTK_TEXT_VIEW(SignUpView1));
// 	g_signal_connect(textBuffer1, "changed", G_CALLBACK(on_changed_text1), NULL); 
// 	g_signal_connect(textBuffer2, "changed", G_CALLBACK(on_changed_text2), NULL); 
// 	g_signal_connect(textBufferSignUp1, "changed", G_CALLBACK(on_changed_text1), NULL);
// 	g_signal_connect(textBufferSignUp2, "changed", G_CALLBACK(on_changed_text2), NULL);

	gtk_widget_show(SignUpWindow);

	gtk_main(); 

	return EXIT_SUCCESS;
}