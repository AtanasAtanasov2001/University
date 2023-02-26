package com.view;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;

public class Controller {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private TextArea txaInventory;

    @FXML
    private Button btnShowInventory;

    @FXML
    private Button btnSort;

    @FXML
    private Button btnFindAverage;

    @FXML
    private Button btnGroup;

    @FXML
    private Button btnQuit;

    @FXML
    void btnFindAverageOnAction(ActionEvent event) {

    }

    @FXML
    void btnGroupOnAction(ActionEvent event) {

    }

    @FXML
    void btnQuitOnAction(ActionEvent event) {

    }

    @FXML
    void btnShowInventoryOnAction(ActionEvent event) {

    }

    @FXML
    void btnSortOnAction(ActionEvent event) {

    }

    @FXML
    void initialize() {
        assert txaInventory != null : "fx:id=\"txaInventory\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnShowInventory != null : "fx:id=\"btnShowInventory\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnSort != null : "fx:id=\"btnSort\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnFindAverage != null : "fx:id=\"btnFindAverage\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnGroup != null : "fx:id=\"btnGroup\" was not injected: check your FXML file 'sample.fxml'.";
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'sample.fxml'.";

    }
}
