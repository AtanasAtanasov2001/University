package com.example.week8;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class FromController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnRegistration;

    @FXML
    private Label lblEmail;

    @FXML
    private Label lblPassword;

    @FXML
    private Label lblPhoneNumber;

    @FXML
    private Label lblUsername;

    @FXML
    private TextField txtConfirmPassword;

    @FXML
    private TextField txtEmail;

    @FXML
    private TextField txtPassword;

    @FXML
    private TextField txtPhoneNumber;

    @FXML
    private TextField txtUsername;

    @FXML
    void btnRegistrationOnAction(ActionEvent event) {
        lblUsername.setText("");
        lblEmail.setText("");
        lblPassword.setText("");
        lblPhoneNumber.setText("");
        if(!txtUsername.getText().matches("[a-zA-Z]{2,}")) {
            lblUsername.setText("Invalid username!");
        }
        if(!txtPhoneNumber.getText().matches("\\(\\d{4}\\)\\(\\d{7}\\)")) {
            lblPhoneNumber.setText("Invalid phone number!");
        }
        if(!txtEmail.getText().matches("([\\w-]+\\.?)+@[-\\w]+\\.[a-zA-Z]{2,4}")) {
            lblEmail.setText("Invalid email!");
        }
        if(txtPassword.getText() == null || txtPassword.getText().equals("")) {
            lblPassword.setText("No password!");
        } else if(!txtPassword.getText().equals(txtConfirmPassword.getText())){
            lblPassword.setText("Confirm password is different!");
        }


        if(lblPhoneNumber.getText().equals("") &&
                lblUsername.getText().equals("") &&
                lblEmail.getText().equals("") &&
                lblPassword.getText().equals("")){
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Successful registration");
            alert.setHeaderText("You registered an account successfully");
            alert.showAndWait();
        }
    }

    @FXML
    void initialize() {
        assert btnRegistration != null : "fx:id=\"btnRegistration\" was not injected: check your FXML file 'form-view.fxml'.";
        assert lblEmail != null : "fx:id=\"lblEmail\" was not injected: check your FXML file 'form-view.fxml'.";
        assert lblPassword != null : "fx:id=\"lblPassword\" was not injected: check your FXML file 'form-view.fxml'.";
        assert lblPhoneNumber != null : "fx:id=\"lblPhoneNumber\" was not injected: check your FXML file 'form-view.fxml'.";
        assert lblUsername != null : "fx:id=\"lblUsername\" was not injected: check your FXML file 'form-view.fxml'.";
        assert txtConfirmPassword != null : "fx:id=\"txtConfirmPassword\" was not injected: check your FXML file 'form-view.fxml'.";
        assert txtEmail != null : "fx:id=\"txtEmail\" was not injected: check your FXML file 'form-view.fxml'.";
        assert txtPassword != null : "fx:id=\"txtPassword\" was not injected: check your FXML file 'form-view.fxml'.";
        assert txtPhoneNumber != null : "fx:id=\"txtPhoneNumber\" was not injected: check your FXML file 'form-view.fxml'.";
        assert txtUsername != null : "fx:id=\"txtUsername\" was not injected: check your FXML file 'form-view.fxml'.";

    }

}
