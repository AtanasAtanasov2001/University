module com.view {
    requires javafx.fxml;
    requires javafx.controls;
    requires data.model;

    opens com.view to javafx.fxml;
    exports com.view to javafx.graphics;
}