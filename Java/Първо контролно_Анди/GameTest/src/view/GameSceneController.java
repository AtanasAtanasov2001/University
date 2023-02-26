package view;

import java.net.URL;
import java.util.ResourceBundle;

import cards.BeziqueCards;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;

public class GameSceneController {

    BeziqueCards beziqueCards = new BeziqueCards();

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnDealHand;

    @FXML
    private Button btnKingAndQueen;

    @FXML
    private Button btnQuit;

    @FXML
    private Button btnAKQJ10;

    @FXML
    private TextArea txaPrintHand;

    @FXML
    private TextArea txaResult;

    @FXML
    void btnAKQJ10OnAction(ActionEvent event) {
        if (beziqueCards.hasAKQJ10() == true){
            txaResult.setText(txaResult.getText() + "\n" +
                    String.format("В изтеглената ръка няма Ace, King, Queen, Jack, Ten от цвят Коз: %s", beziqueCards.getTrump().name()));
        }
    }

    @FXML
    void btnDealHandOnAction(ActionEvent event) {
        txaPrintHand.setText("");
        beziqueCards.shuffleCards();
        beziqueCards.dealHand();
        txaPrintHand.setText(beziqueCards.printCards());
    }

    @FXML
    void btnKingAndQueenOnAction(ActionEvent event) {
        if (beziqueCards.hasMarriage() == true) {
            txaResult.setText(txaResult.getText() + "\n" +
                    String.format("В изтеглената ръка има двойка King-Queen от цвят Коз: %s", beziqueCards.getTrump().name()));
        }
    }

    @FXML
    void btnQuitOnAction(ActionEvent event) {
        Platform.exit();
    }

    @FXML
    void initialize() {
        assert btnDealHand != null : "fx:id=\"btnDealHand\" was not injected: check your FXML file 'GameScene.fxml'.";
        assert btnKingAndQueen != null : "fx:id=\"btnKingAndQueen\" was not injected: check your FXML file 'GameScene.fxml'.";
        assert btnQuit != null : "fx:id=\"btnQuit\" was not injected: check your FXML file 'GameScene.fxml'.";
        assert btnAKQJ10 != null : "fx:id=\"btnAKQJ10\" was not injected: check your FXML file 'GameScene.fxml'.";
        assert txaPrintHand != null : "fx:id=\"txaPrintHand\" was not injected: check your FXML file 'GameScene.fxml'.";
        assert txaResult != null : "fx:id=\"txaResult\" was not injected: check your FXML file 'GameScene.fxml'.";

    }
}
