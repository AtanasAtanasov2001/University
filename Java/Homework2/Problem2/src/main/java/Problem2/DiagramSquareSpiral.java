package Problem2;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

import java.io.IOException;

public class DiagramSquareSpiral extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        Group group = new Group();
        int width = 600;
        int height = 600;
        Scene scene = new Scene(group, width, height);
        double guidePointX = width/12;
        double guidePointY = height/12;
        for (int i = 1; i <= 5 ; i++) {
            Line line1 = new Line(i*guidePointX,i*guidePointY,width-i*guidePointX,i*guidePointY);
            Line line2 = new Line(i*guidePointX,i*guidePointY,i*guidePointX,height-i*guidePointY);
            Line line3 = new Line(i*guidePointX,height-i*guidePointY,width-(i*guidePointX)-guidePointX,height-i*guidePointY);
            Line line4 = new Line(width- i*guidePointX - guidePointX ,height-i*guidePointY,width - i*guidePointX - guidePointX,i*guidePointY + guidePointY);

            line1.setStroke(Color.RED);
            group.getChildren().add(line1);
            line2.setStroke(Color.RED);
            group.getChildren().add(line2);
            line3.setStroke(Color.RED);
            group.getChildren().add(line3);
            line4.setStroke(Color.RED);
            group.getChildren().add(line4);

            stage.setTitle("Draw sqare shaped spiral");
            stage.setScene(scene);
            stage.show();
        }
    }

    public static void main(String[] args) {
        launch();
    }
}