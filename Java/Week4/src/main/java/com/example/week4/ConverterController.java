package com.example.week4;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

import java.net.URL;
import java.util.Locale;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TextField;

    public class ConverterController {

        @FXML
        private ResourceBundle resources;

        @FXML
        private URL location;

        @FXML
        private Button btnBinary;

        @FXML
        private Button btnDecimal;

        @FXML
        private Button btnHex;

        @FXML
        private MenuItem mniBinary;

        @FXML
        private MenuItem mniDecimal;

        @FXML
        private MenuItem mniHex;

        @FXML
        private MenuItem mniQuit;

        @FXML
        private Menu mnu;

        @FXML
        private Menu mnuQuit;

        @FXML
        private TextField txtBinary;

        @FXML
        private TextField txtDecimal;

        @FXML
        private TextField txtHex;

        @FXML
        void btnBinaryOnAction(ActionEvent event) {
            convertBinary();
        }

        @FXML
        void btnDecimalOnAction(ActionEvent event) {
            convertDecimal();
        }

        @FXML
        void btnHexOnAction(ActionEvent event) {
            convertHex();
        }

        @FXML
        void mniBinaryOnAction(ActionEvent event) {
            convertBinary();
        }

        @FXML
        void mniDecimalOnAction(ActionEvent event) {
            convertDecimal();
        }

        @FXML
        void mniHexOnAction(ActionEvent event) {
            convertHex();
        }

        @FXML
        void mniQuitOnAction(ActionEvent event) {
            Platform.exit();
        }

        @FXML
        void txtBinaryOnAction(ActionEvent event) {
            convertBinary();
        }

        @FXML
        void txtDecimalOnAction(ActionEvent event) {
            convertDecimal();
        }

        @FXML
        void txtHexlOnAction(ActionEvent event) {
            convertHex();
        }
        private void convertBinary() {
            String binaryText = txtBinary.getText();
            if(binaryText.length() > 0) {
                int decimalNumber = Integer.parseInt(binaryText, 2);
                txtDecimal.setText(Integer.toString(decimalNumber));
                txtHex.setText(Integer.toHexString(decimalNumber).toUpperCase());

            }
        }
        private void convertDecimal() {
            String decimalText = txtDecimal.getText();
            if(decimalText.length() > 0) {
                int decimalNumber = Integer.parseInt(decimalText);
                txtBinary.setText(Integer.toBinaryString(decimalNumber));
                txtHex.setText(Integer.toHexString(decimalNumber).toUpperCase());

            }
        }
        private void convertHex() {
            String hexText = txtHex.getText();
            if(hexText.length() > 0) {
                int decimalNumber = Integer.parseInt(hexText, 16);
                txtDecimal.setText(Integer.toString(decimalNumber));
                txtBinary.setText(Integer.toBinaryString(decimalNumber));

            }
        }


        @FXML
        void initialize() {
            assert btnBinary != null : "fx:id=\"btnBinary\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert btnDecimal != null : "fx:id=\"btnDecimal\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert btnHex != null : "fx:id=\"btnHex\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert mniBinary != null : "fx:id=\"mniBinary\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert mniDecimal != null : "fx:id=\"mniDecimal\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert mniHex != null : "fx:id=\"mniHex\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert mniQuit != null : "fx:id=\"mniQuit\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert mnu != null : "fx:id=\"mnu\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert mnuQuit != null : "fx:id=\"mnuQuit\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert txtBinary != null : "fx:id=\"txtBinary\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert txtDecimal != null : "fx:id=\"txtDecimal\" was not injected: check your FXML file 'converter-view.fxml'.";
            assert txtHex != null : "fx:id=\"txtHex\" was not injected: check your FXML file 'converter-view.fxml'.";

        }

    }

