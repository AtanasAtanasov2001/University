package com.example.newgametest;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class GameTestController {
    private EuchereGame;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnDrawCards;

    @FXML
    private Button btnExit;

    @FXML
    private Button btnHasTrumpsJackAce;

    @FXML
    private Button btnTrumpsKingQueenJack;

    @FXML
    void btnDrawCardsOnAction(ActionEvent event) {
        EuchereGame.dealHand();
    }

    @FXML
    void btnExitOnAction(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void btnHasTrumpsJackAceOnAction(ActionEvent event) {
        EuchereGame.hasJackANDAceTrump();
    }

    @FXML
    void btnTrumpsKingQueenJackOnAction(ActionEvent event) {
        EuchereGame.hasJackQueenKingTrump();
    }

    @FXML
    void initialize() {
        assert btnDrawCards != null : "fx:id=\"btnDrawCards\" was not injected: check your FXML file 'gameTest-view.fxml'.";
        assert btnExit != null : "fx:id=\"btnExit\" was not injected: check your FXML file 'gameTest-view.fxml'.";
        assert btnHasTrumpsJackAce != null : "fx:id=\"btnHasTrumpsJackAce\" was not injected: check your FXML file 'gameTest-view.fxml'.";
        assert btnTrumpsKingQueenJack != null : "fx:id=\"btnTrumpsKingQueenJack\" was not injected: check your FXML file 'gameTest-view.fxml'.";

    }

}