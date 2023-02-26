package com.example.week2problem2;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.shape.Line;
import javafx.scene.paint.Color;

import java.io.IOException;

public class DrawCircles extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        //FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        Group group = new Group(); //panel
        Scene scene = new Scene(group, 500, 600);

        double width = scene.getWidth();
        double height = scene.getHeight();

        double centerX = width/2;
        double centerY = height/2;

        int radius = 10;
        int counter = 1;
        while(counter < 13) {
            Circle circle = new Circle(centerX, centerY, radius);
            circle.setStroke(Color.BLUE);
            circle.setFill(Color.TRANSPARENT);

            group.getChildren().add(circle);
            radius += 10;
            counter++;
        }
        double xH = centerX - 12*10;
        double yV = centerY - 12*10;
        Line horizontalDiameter = new Line (xH,centerY, xH + 12*20, centerY);
        horizontalDiameter.setStroke(Color.RED);
        horizontalDiameter.setStrokeWidth(3);

        Line verticalDiameter = new Line (centerX,yV,centerX, yV + 12*20);
        verticalDiameter.setStroke(Color.RED);
        verticalDiameter.setStrokeWidth(3);

        group.getChildren().add(horizontalDiameter);
        group.getChildren().add(verticalDiameter);
        stage.setTitle("Draw");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}