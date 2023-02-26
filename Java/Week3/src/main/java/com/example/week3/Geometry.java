package com.example.week3;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;
import javafx.scene.Group;
import javafx.scene.control.Alert;
import javafx.scene.control.TextInputDialog;
import javafx.scene.text.Text;
import javafx.scene.shape.Line;

        import java.io.IOException;

public class Geometry extends Application {
    private double xOffset;
    private Group root;
    private Alert errorDlg;
    private TextInputDialog dlg;
    private Scene scene;

    private void readInput() {
        dlg.setTitle("Input data");
        dlg.setContentText("Enter x: ");
        do {
            xOffset = Double.parseDouble(dlg.showAndWait().get());
        }while (xOffset < 0 || xOffset > scene.getWidth());// validate x
    }

    private  void showAlert() {
        errorDlg.setTitle("Input error: ");
        errorDlg.setHeaderText("No intersections");
        errorDlg.showAndWait();
    }

    private void drawCircleAndText(double yCrossPoint) {
        Circle point = new Circle(xOffset, yCrossPoint, 5);
        point.setStroke(Color.BLACK);

        Text text = new Text(xOffset + 10 , yCrossPoint,
                String.format("(%.2f; %.2f)", xOffset, yCrossPoint));
        root.getChildren().addAll(point, text);
    }
    @Override
    public void start(Stage stage) throws IOException {
        root = new Group();
        scene = new Scene(root, 300, 250);
        dlg = new TextInputDialog();
        errorDlg = new Alert(Alert.AlertType.ERROR);

        double radius;
        double centerX, centerY;
        double discriminant;

        //input
        readInput();
        centerX = scene.getWidth()/2;
        centerY = scene.getHeight()/2;
        radius = Math.min(scene.getWidth(), scene.getHeight())/3; // Math.min - double

        //calculations
        discriminant = radius * radius - (centerX - xOffset)*(centerX - xOffset);

        Circle circle = new Circle(centerX, centerY, radius);
        circle.setStroke(Color.BLUE);
        circle.setFill(null);
        root.getChildren().add(circle);

        //draw intersection points
        if(discriminant >= 0 ) {
            //1 or 2 intersection points
            Line line = new Line(xOffset, 0, xOffset, scene.getHeight());
            line.setStroke(Color.RED);
            root.getChildren().add(line);

            double yCrossPoint = centerY - Math.sqrt(discriminant);
            drawCircleAndText(yCrossPoint);
            if(discriminant > 0 ){
                double yCrossPoint2 = centerY + Math.sqrt(discriminant);
                drawCircleAndText( yCrossPoint2);
            }
        }
        else {
          showAlert();// no intersection
          Platform.exit();
        }
        stage.setTitle("Circle Line Intersection");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}