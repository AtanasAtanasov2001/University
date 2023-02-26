package months;

public enum Months {
    JAN{
        @Override
        public String toString() {
            return "January";
        }
    },
    FEB{
        @Override
        public String toString() {
            return "February";
        }
    },
    MAR{
        @Override
        public String toString() {
            return "March";
        }
    },
    APR{
        @Override
        public String toString() {
            return "April";
        }
    },
    MAY{
        @Override
        public String toString() {
            return "May";
        }
    },
    JUN{
        @Override
        public String toString() {
            return "June";
        }
    },
    JUL{
        @Override
        public String toString() {
            return "July";
        }
    },
    AUG{
        @Override
        public String toString() {
            return "August";
        }
    },
    SEP{
        @Override
        public String toString() {
            return "September";
        }
    },
    OCT{
        @Override
        public String toString() {
            return "October";
        }
    },
    NOV{
        @Override
        public String toString() {
            return "November";
        }
    },
    DEC{
        @Override
        public String toString() {
            return "December";
        }
    };

    public abstract String toString();
}
