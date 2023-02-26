package Problem1;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextInputDialog;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.paint.Color;

import java.io.IOException;
import java.time.DayOfWeek;
import java.time.LocalDate;
import java.util.*;

public class CalendarP1 extends Application {

    public boolean isPresentDay(LocalDate date) {
        LocalDate presentDay = LocalDate.now();
        return date.getMonth().equals(presentDay.getMonth()) && date.getYear() == presentDay.getYear();
    }
    public void start(Stage stage) throws IOException {

        Group group = new Group();
        Scene scene = new Scene(group, 350,350);
        double canvasRange = (scene.getWidth() - 80 )/7 ;
        TextInputDialog month = new TextInputDialog();
        month.setTitle("Choose month");
        month.setHeaderText("Enter month: ");
        Optional <String> month_optional = month.showAndWait();


        TextInputDialog year = new TextInputDialog();
        year.setTitle("Choose year");
        year.setHeaderText("Enter year: ");
        Optional <String> year_optional = year.showAndWait();

        LocalDate date = LocalDate.of(Integer.parseInt(year_optional.get()), Integer.parseInt(month_optional.get()),1);
        stage.setTitle("Calendar for " + date.getMonth().toString() + date.getYear());
        Text days = new Text("MON     TUE     WED     THR     FRI     SAT     SUN");
        days.setX(50);
        days.setY(50);
        days.setStroke(Color.BLUE);
        group.getChildren().add(days);


        int daysMonth = date.lengthOfMonth();

        int dayOfWeek = 0;
        if(isPresentDay(date)) {
            dayOfWeek = LocalDate.now().getDayOfMonth();
        }
        for (int i = 1; i <= daysMonth ; i++) {
            LocalDate tempDate = LocalDate.of(Integer.parseInt(year_optional.get()),
                    Integer.parseInt(month_optional.get()),i);
            DayOfWeek day = tempDate.getDayOfWeek();

            switch (day.getValue()) {
                case 1 -> {
                    Text positionOfDay1 = new Text(String.valueOf(i));
                    positionOfDay1.setX(55);
                    positionOfDay1.setY(100 + 5 * i);
                    if (i == dayOfWeek) {
                        positionOfDay1.setStroke(Color.RED);
                    } else {
                        positionOfDay1.setStroke(Color.BLACK);
                    }
                    group.getChildren().add(positionOfDay1);
                }
                case 2 -> {
                    Text positionOfDay2 = new Text(String.valueOf(i));
                    positionOfDay2.setX(60 + canvasRange);
                    positionOfDay2.setY(100 + 5 * i - 5);
                    if (i == dayOfWeek) {
                        positionOfDay2.setStroke(Color.RED);
                    } else {
                        positionOfDay2.setStroke(Color.BLACK);
                    }
                    group.getChildren().add(positionOfDay2);
                }
                case 3 -> {
                    Text positionOfDay3 = new Text(String.valueOf(i));
                    positionOfDay3.setX(60 + canvasRange * 2);
                    positionOfDay3.setY(100 + 5 * i - 10);
                    if (i == dayOfWeek) {
                        positionOfDay3.setStroke(Color.RED);
                    } else {
                        positionOfDay3.setStroke(Color.BLACK);
                    }
                    group.getChildren().add(positionOfDay3);
                }
                case 4 -> {
                    Text positionOfDay4 = new Text(String.valueOf(i));
                    positionOfDay4.setX(60 + canvasRange * 3);
                    positionOfDay4.setY(100 + 5 * i - 15);
                    if (i == dayOfWeek) {
                        positionOfDay4.setStroke(Color.RED);
                    } else {
                        positionOfDay4.setStroke(Color.BLACK);
                    }
                    group.getChildren().add(positionOfDay4);
                }
                case 5 -> {
                    Text positionOfDay5 = new Text(String.valueOf(i));
                    positionOfDay5.setX(60 + canvasRange * 4);
                    positionOfDay5.setY(100 + 5 * i - 20);
                    if (i == dayOfWeek) {
                        positionOfDay5.setStroke(Color.RED);
                    } else {
                        positionOfDay5.setStroke(Color.BLACK);
                    }
                    group.getChildren().add(positionOfDay5);
                }
                case 6 -> {
                    Text positionOfDay6 = new Text(String.valueOf(i));
                    positionOfDay6.setX(60 + canvasRange * 5);
                    positionOfDay6.setY(100 + 5 * i - 25);
                    if (i == dayOfWeek) {
                        positionOfDay6.setStroke(Color.RED);
                    } else {
                        positionOfDay6.setStroke(Color.BLACK);
                    }
                    group.getChildren().add(positionOfDay6);
                }
                case 7 -> {
                    Text positionOfDay7 = new Text(String.valueOf(i));
                    positionOfDay7.setX(60 + canvasRange * 6);
                    positionOfDay7.setY(100 + 5 * i - 30);
                    if (i == dayOfWeek) {
                        positionOfDay7.setStroke(Color.RED);
                    } else {
                        positionOfDay7.setStroke(Color.BLACK);
                    }
                    group.getChildren().add(positionOfDay7);
                }
            }
        }
        stage.setScene(scene);
        stage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }
}