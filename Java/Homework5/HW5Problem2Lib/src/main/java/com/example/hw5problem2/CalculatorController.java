package com.example.hw5problem2;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;

public class CalculatorController extends AnchorPane {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnClear;

    @FXML
    private Button btnClearLast;

    @FXML
    private Button btnDivide;

    @FXML
    private Button btnDot;

    @FXML
    private Button btnDoubleZero;

    @FXML
    private Button btnEight;

    @FXML
    private Button btnEqual;

    @FXML
    private Button btnFive;

    @FXML
    private Button btnFour;

    @FXML
    private Button btnMinus;

    @FXML
    private Button btnMultiply;

    @FXML
    private Button btnNine;

    @FXML
    private Button btnOff;
    @FXML
    private Button btnOne;

    @FXML
    private Button btnPlus;

    @FXML
    private Button btnSeven;

    @FXML
    private Button btnSix;

    @FXML
    private Button btnThree;

    @FXML
    private Button btnTwo;

    @FXML
    private Button btnZero;

    @FXML
    private TextField txtOutput;
    private double helperOne;
    private double helperTwo;
    private String operation;

    public TextField getTxtOutput() {
        return txtOutput;
    }

    public CalculatorController() {
        FXMLLoader fmxmlLoader = new FXMLLoader(getClass().getResource("calculator-view.fxml"));

        fmxmlLoader.setRoot(this);
        fmxmlLoader.setController(this);

        try {
            fmxmlLoader.load();
        } catch (IOException exception) {
            throw new RuntimeException(exception);
        }

    }
    @FXML
    void btnClearLastOnAction(ActionEvent event) {
        String value = txtOutput.getText();
        StringBuffer sb = new StringBuffer(value);
        sb.deleteCharAt(sb.length() - 1);
        txtOutput.setText(sb.toString());

    }

    @FXML
    void btnClearOnAction(ActionEvent event) {
        txtOutput.setText("");
        helperOne = 0;
        helperTwo = 0;
        operation = "";
    }

    @FXML
    void btnDivideOnAction(ActionEvent event) {

        if(operation.equals("+") || operation.equals("-") || operation.equals("*")) {
            this.operation = "/";
            btnClearLastOnAction(event);
            txtOutput.setText(txtOutput.getText() + "/");
        }
        else if(!operation.equals("=") && operation.equals("/")) {
            this.operation = "/";
            btnEqualOnAction(event);
            txtOutput.setText(txtOutput.getText() + "/");
        }
        else {
            String value = txtOutput.getText();
            double valueNumber = Double.parseDouble(value);
            this.helperOne = valueNumber;
            txtOutput.setText(value + "/" );
            this.operation = "/";
        }

    }

    @FXML
    void btnDotOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = ".";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnDoubleZeroOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "00";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnEightOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "8";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnEqualOnAction(ActionEvent event) {
        switch (operation) {
            case "+" -> {
                String valuePlus = txtOutput.getText();
                this.helperTwo = Double.parseDouble(txtOutput.getText().substring(txtOutput.getText().indexOf('+') + 1,valuePlus.length()));
                double systemPlus = this.helperOne + this.helperTwo;
                helperOne = systemPlus;
                txtOutput.setText(String.valueOf(systemPlus));
            }
            case "-" -> {
                String valueMinus = txtOutput.getText();
                this.helperTwo = Double.parseDouble(txtOutput.getText().substring(txtOutput.getText().indexOf('-') + 1,valueMinus.length()));
                double systemMinus = this.helperOne - this.helperTwo;
                helperOne = systemMinus;
                txtOutput.setText(String.valueOf(systemMinus));
            }
            case "*" -> {
                String valueMulti = txtOutput.getText();
                this.helperTwo = Double.parseDouble(txtOutput.getText().substring(txtOutput.getText().indexOf('*') + 1,valueMulti.length()));
                double systemMulti = this.helperOne * this.helperTwo;
                helperOne = systemMulti;
                txtOutput.setText(String.valueOf(systemMulti));
            }
            case "/" -> {
                String valueDivide = txtOutput.getText();
                this.helperTwo = Double.parseDouble(txtOutput.getText().substring(txtOutput.getText().indexOf('/') + 1,valueDivide.length()));
                double systemDivide = this.helperOne / this.helperTwo;
                helperOne = systemDivide;
                txtOutput.setText(String.valueOf(systemDivide));
            }
        }
        operation = "=";
    }

    @FXML
    void btnFiveOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "5";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnFourOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "4";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnMinusOnActon(ActionEvent event) {
        if(operation.equals("+") || operation.equals("/") || operation.equals("*")) {
            this.operation = "-";
            btnClearLastOnAction(event);
            txtOutput.setText(txtOutput.getText() + "-");
        }
        else if(operation.equals("-") ) {
            this.operation = "-";
            btnEqualOnAction(event);
            txtOutput.setText(txtOutput.getText() + "-");
        }
        else {
            String value = txtOutput.getText();
            double valueNumber = Double.parseDouble(value);
            this.helperOne = valueNumber;
            txtOutput.setText(value + "-" );
            this.operation = "-";
        }
    }

    @FXML
    void btnMultiplyOnAction(ActionEvent event) {
        if(operation.equals("+") || operation.equals("-") || operation.equals("/")) {
            this.operation = "*";
            btnClearLastOnAction(event);
            txtOutput.setText(txtOutput.getText() + "*");
        }
        else if(operation.equals("*") ) {
            this.operation = "*";
            btnEqualOnAction(event);
            txtOutput.setText(txtOutput.getText() + "*");
        }
        else {
            String value = txtOutput.getText();
            double valueNumber = Double.parseDouble(value);
            this.helperOne = valueNumber;
            txtOutput.setText(value + "*" );
            this.operation = "*";
        }
    }

    @FXML
    void btnNineOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "9";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnOffOnAction(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void btnOneOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "1";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnPlusOnAction(ActionEvent event) {
        if(operation.equals("/") || operation.equals("-") || operation.equals("*")) {
            this.operation = "+";
            btnClearLastOnAction(event);
            txtOutput.setText(txtOutput.getText() + "+");
        }
        else if(operation.equals("+")) {
            this.operation = "+";
            btnEqualOnAction(event);
            txtOutput.setText(txtOutput.getText() + "+");
        }
        else {
            String value = txtOutput.getText();
            double valueNumber = Double.parseDouble(value);
            this.helperOne = valueNumber;
            txtOutput.setText(value + "+" );
            this.operation = "+";
        }
    }

    @FXML
    void btnSevenOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "7";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnSixOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "6";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnThreeOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "3";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnTwoOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "2";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void btnZeroOnAction(ActionEvent event) {
        String oldValue = txtOutput.getText();
        String set = "0";
        txtOutput.setText(oldValue + set);
    }

    @FXML
    void txtOutputOnAction(ActionEvent event) {

    }

    @FXML
    void initialize() {
        assert btnClear != null : "fx:id=\"btnClear\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnClearLast != null : "fx:id=\"btnClearLast\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnDivide != null : "fx:id=\"btnDivide\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnDot != null : "fx:id=\"btnDot\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnDoubleZero != null : "fx:id=\"btnDoubleZero\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnEight != null : "fx:id=\"btnEight\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnEqual != null : "fx:id=\"btnEqual\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnFive != null : "fx:id=\"btnFive\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnFour != null : "fx:id=\"btnFour\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnMinus != null : "fx:id=\"btnMinus\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnMultiply != null : "fx:id=\"btnMultiply\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnNine != null : "fx:id=\"btnNine\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnOff != null : "fx:id=\"btnOff\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnOne != null : "fx:id=\"btnOne\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnPlus != null : "fx:id=\"btnPlus\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnSeven != null : "fx:id=\"btnSeven\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnSix != null : "fx:id=\"btnSix\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnThree != null : "fx:id=\"btnThree\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnTwo != null : "fx:id=\"btnTwo\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnZero != null : "fx:id=\"btnZero\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert txtOutput != null : "fx:id=\"txtOutput\" was not injected: check your FXML file 'calculator-view.fxml'.";
        operation = "";
    }

}
