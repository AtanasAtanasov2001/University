package com.example.week8problem3;

import java.net.URL;
import java.util.Arrays;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class SortController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnQuit;

    @FXML
    private Button btnSort;

    @FXML
    private Label lblOrder;

    @FXML
    private Label lblSorted;

    @FXML
    private Label lblUnsorted;

    @FXML
    private TextField txtOrdered;

    @FXML
    private TextArea txaSorted;

    @FXML
    private TextArea txaUnsorted;

    @FXML
    void btnQuitOnAction(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void btnSortOnAction(ActionEvent event) {
        String unsorted = txaUnsorted.getText();
        String[] array = unsorted.split("\\s+");
        for (int i = 0; i < array.length; i++) {
            if(array[i].matches("[1-9]+[0-9]*|0")){
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Invalid input");
                alert.setHeaderText("Array element not an integer");
                alert.showAndWait();
                Platform.exit();
            }
        }
        if(txtOrdered.getText().matches("Y|y")){
            Arrays.sort(array);
            txaSorted.setText(Arrays.toString(array));
        }
    }

    @FXML
    void initialize() {
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'sort-view.fxml'.";
        assert btnSort != null : "fx:id=\"btnSort\" was not injected: check your FXML file 'sort-view.fxml'.";
        assert lblOrder != null : "fx:id=\"lblOrder\" was not injected: check your FXML file 'sort-view.fxml'.";
        assert lblSorted != null : "fx:id=\"lblSorted\" was not injected: check your FXML file 'sort-view.fxml'.";
        assert lblUnsorted != null : "fx:id=\"lblUnsorted\" was not injected: check your FXML file 'sort-view.fxml'.";
        assert txtOrdered != null : "fx:id=\"txtOrdered\" was not injected: check your FXML file 'sort-view.fxml'.";
        assert txaSorted != null : "fx:id=\"txtSorted\" was not injected: check your FXML file 'sort-view.fxml'.";
        assert txaUnsorted != null : "fx:id=\"txtUnsorted\" was not injected: check your FXML file 'sort-view.fxml'.";

    }

}
