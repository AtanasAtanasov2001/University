package lab7;

import geometry.Point;
import geometry.Rectangle;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.Random;

public class GeometryTest extends Application {
    @Override
    public void start(Stage stage) throws Exception {
        Group pane = new Group();
        Scene scene = new Scene(pane, 500,300);

        Random random = new Random();

        double randomX = random.nextInt(50_001)/100.0;
        double randomY = random.nextInt(30_001)/100.0;

        Point p1 = new Point(new double[]{randomX,randomY});


        randomX = random.nextInt(50_001)/100.0;
        randomY = random.nextInt(30_001)/100.0;

        Point p2 = new Point(new double[]{randomX,randomY});

        //validate if rectangle is in scene
        Rectangle r1 = new Rectangle(p1, 50,30);
        Rectangle r2 = new Rectangle(p2, 20,20);

        r1.draw(pane);
        r2.draw(pane);

        stage.setTitle("Geometry");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
