package com.example.exam_gui;

import java.net.URL;
import java.util.ResourceBundle;

import exam.logic.InvoiceProcessing;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;

public class HelloController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnFind;

    @FXML
    private Button btnGroup;

    @FXML
    private Button btnQuit;

    @FXML
    private Button btnShow;

    @FXML
    private Button btnSort;

    @FXML
    private TextArea txaWindow;
    private InvoiceProcessing invoiceProcessing;
    @FXML
    void btnFindOnAction(ActionEvent event) {

    }

    @FXML
    void btnGroupOnAction(ActionEvent event) {

    }

    @FXML
    void btnQuitOnAction(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void btnShowOnAction(ActionEvent event) {
        txaWindow.setText(invoiceProcessing.showInvoices());
    }

    @FXML
    void btnSortOnAction(ActionEvent event) {

    }

    @FXML
    void initialize() {
        assert btnFind != null : "fx:id=\"btnFind\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert btnGroup != null : "fx:id=\"btnGroup\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert btnShow != null : "fx:id=\"btnShow\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert btnSort != null : "fx:id=\"btnSort\" was not injected: check your FXML file 'hello-view.fxml'.";
        assert txaWindow != null : "fx:id=\"txaWindow\" was not injected: check your FXML file 'hello-view.fxml'.";
        invoiceProcessing = new InvoiceProcessing(2);
    }

}
