GtkWidget	*SignUpWindow;
GtkWidget	*SignUpFixed;
GtkWidget	*SignUpTitle;
GtkWidget	*SignUpLogin;
GtkWidget	*SignUpPassword;
GtkWidget	*SignUpName;
GtkWidget	*SignUpDateOfBirth;
GtkWidget	*SignUpPhoneNumber;
GtkWidget	*SignUpPasswordSerialNumber,*SignUpBtnsave;



GtkBuilder	*builder;

int main3() {
	builder = gtk_builder_new_from_file ("auth.glade");

	SignUpWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpWindow"));

	SignUpFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpFixed"));
	
	SignUpTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpTitle"));
	SignUpLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpLogin"));

	// SignUpBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpBtn"));

	SignUpBtnsave = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpBtnsave"));


	SignUpPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPassword"));	

	
	SignUpName = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpName"));

	SignUpDateOfBirth = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpDateOfBirth"));

	SignUpPhoneNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPhoneNumber"));

	SignUpPasswordSerialNumber = GTK_WIDGET(gtk_builder_get_object(builder, "SignUpPasswordSerialNumber"));



	gtk_widget_show(SignUpWindow);

	gtk_main(); 

	return EXIT_SUCCESS;
}
void submit_signup(GtkButton *b){
	printf("Button clicked\n");
}