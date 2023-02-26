package Problem2;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;
import java.io.IOException;

public class Diagram extends Application {

    @Override
    public void start(Stage stage) {
        Group group = new Group();
        Scene scene = new Scene(group, 600, 600);
        for (int i = 0; i <= 600; i += 28 ) {
            Line line1 = new Line(i,0,600,i);
            Line line2 = new Line(i,600,600,600-i);
            Line line3 = new Line(i,0,0,600-i);
            Line line4 = new Line(i,600,0,i);

            line1.setStroke(Color.ORANGE);
            group.getChildren().add(line1);
            line2.setStroke(Color.ORANGE);
            group.getChildren().add(line2);
            line3.setStroke(Color.ORANGE);
            group.getChildren().add(line3);
            line4.setStroke(Color.ORANGE);
            group.getChildren().add(line4);


        }

        stage.setTitle("Draw");
        stage.setScene(scene);
        stage.show();



    }
    public static void main(String[] args) {
        launch(args);
    }
}
