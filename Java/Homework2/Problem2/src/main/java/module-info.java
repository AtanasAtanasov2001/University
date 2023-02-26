module com.example.homework2problem1 {
    requires javafx.controls;
    requires javafx.fxml;


    opens Problem2 to javafx.fxml;
    exports Problem2;
}