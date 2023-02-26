package com.example.hw5problem2solution;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import com.example.hw5problem2.*;

public class CalculatorControllerTwo {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnAdd;

    @FXML
    private Button btnClear;

    @FXML
    private Button btnSave;

    @FXML
    private Button btnSubtract;

    @FXML
    private CalculatorController calcLib;
    private double savedNum;

    @FXML
    void btnAddOnAction(ActionEvent event) {
        double currentNumber = Double.parseDouble(calcLib.getTxtOutput().getText());
        calcLib.getTxtOutput().setText("" + (currentNumber + savedNum));
    }

    @FXML
    void btnClearOnAction(ActionEvent event) {
        calcLib.getTxtOutput().setText("");
        savedNum = 0;

    }

    @FXML
    void btnSaveOnAction(ActionEvent event) {
        savedNum = Double.parseDouble(calcLib.getTxtOutput().getText());
    }

    @FXML
    void btnSubtractOnAction(ActionEvent event) {
        double currentNumber = Double.parseDouble(calcLib.getTxtOutput().getText());
        calcLib.getTxtOutput().setText("" + (currentNumber - savedNum));
    }

    @FXML
    void initialize() {
        assert btnAdd != null : "fx:id=\"btnAdd\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnClear != null : "fx:id=\"btnClear\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnSave != null : "fx:id=\"btnSave\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert btnSubtract != null : "fx:id=\"btnSubtract\" was not injected: check your FXML file 'calculator-view.fxml'.";
        assert calcLib != null : "fx:id=\"calcLib\" was not injected: check your FXML file 'calculator-view.fxml'.";

    }

}
