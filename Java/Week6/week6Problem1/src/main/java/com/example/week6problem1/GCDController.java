package com.example.week6problem1;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class GCDController {


        @FXML
        private ResourceBundle resources;

        @FXML
        private URL location;

        @FXML
        private Button btnComputeGcd;

        @FXML
        private Button btnQut;

        @FXML
        private Label lblA;

        @FXML
        private Label lblB;

        @FXML
        private Label lblGdc;

        @FXML
        private TextField txtA;

        @FXML
        private TextField txtB;

        @FXML
        private TextField txtGcd;

        @FXML
        void btnComputeGcdOnAction(ActionEvent event) {
            int a = Integer.parseInt(txtA.getText());
            int b = Integer.parseInt(txtB.getText());
            txtGcd.setText(String.format("%d", computeGcd(a,b)));
        }

        private int computeGcd(int a, int b){
            if(b == 0) {
                return a;
            }
            return computeGcd(b,a % b);
        }

        @FXML
        void btnQutOnAction(ActionEvent event) {
            Platform.exit();
        }

        @FXML
        void initialize() {
            assert btnComputeGcd != null : "fx:id=\"btnComputeGcd\" was not injected: check your FXML file 'gcd-view.fxml'.";
            assert btnQut != null : "fx:id=\"btnQut\" was not injected: check your FXML file 'gcd-view.fxml'.";
            assert lblA != null : "fx:id=\"lblA\" was not injected: check your FXML file 'gcd-view.fxml'.";
            assert lblB != null : "fx:id=\"lblB\" was not injected: check your FXML file 'gcd-view.fxml'.";
            assert lblGdc != null : "fx:id=\"lblGdc\" was not injected: check your FXML file 'gcd-view.fxml'.";
            assert txtA != null : "fx:id=\"txtA\" was not injected: check your FXML file 'gcd-view.fxml'.";
            assert txtB != null : "fx:id=\"txtB\" was not injected: check your FXML file 'gcd-view.fxml'.";
            assert txtGcd != null : "fx:id=\"txtGcd\" was not injected: check your FXML file 'gcd-view.fxml'.";

        }

}


