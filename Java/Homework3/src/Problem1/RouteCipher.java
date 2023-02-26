package Problem1;

public class RouteCipher {
    private int key;

    public RouteCipher(int key) {
        setKey(key);
    }

    public int getKey() {
        return key;
    }

    public void setKey(int key) {
        this.key = key;
    }
    public String stringLength(String plainText) {
        String toReturn = "";
        for (int i = 0; i < plainText.length(); i++){
            if(('a' <= plainText.charAt(i) && plainText.charAt(i) <= 'z') || ('A' <= plainText.charAt(i) && plainText.charAt(i) <= 'Z')) {
                toReturn += plainText.charAt(i);
            }
        }
        return toReturn;
    }
    public String anticlockwiseTopSpiral(char[][] grid, int startRow,
                                    int startCol, int endRow, int endCol, int elements)
    {
        String toReturn = "";
        while(elements != 0) {
            // Top to bottom direction
            for (int i = startRow; i <= endRow &&
                    elements > 0; ++i, elements--)
            {
                toReturn += grid[i][startRow];
            }

            // Left to right direction
            for (int i = startRow + 1; i <= endCol &&
                    elements > 0; ++i, elements--)
            {
                toReturn += grid[endRow][i];
            }
            // Bottom to top direction
            for (int i = endRow - 1; i > startRow &&
                    elements > 0; --i, elements--)
            {
                toReturn += grid[i][endCol];
            }
            // Right to left direction
            for (int i = endCol; i > startCol &&
                    elements > 0; --i, elements--)
            {
                toReturn += grid[startRow][i];
            }
            startRow ++;
            startCol++;
            endRow--;
            endCol--;
        }

        return toReturn;
    }
    public String anticlockwiseBottomSpiral(char[][] grid, int startRow,
                                         int startCol, int endRow, int endCol, int elements)
    {
        String toReturn = "";
        while(elements != 0) {

            // Bottom to top direction
            for (int i = startRow ; i >= endRow &&
                    elements > 0; --i, elements--)
            {
                toReturn += grid[i][startCol];
            }
            startCol--;

            // Right to left direction
            for (int i = startCol; i >= endCol &&
                    elements > 0; --i, elements--)
            {
                toReturn += grid[endRow][i];
            }
            endRow++;
            // Top to bottom direction
            for (int i = endRow; i <= startRow &&
                    elements > 0; ++i, elements--)
            {
                toReturn += grid[i][endCol];
            }
            endCol++;

            // Left to right direction
            for (int i = endCol; i <= startCol &&
                    elements > 0; ++i, elements--)
            {
                toReturn += grid[startRow][i];
            }
            startRow--;
        }

        return toReturn;
    }
    public String encrypt(String plainText) {
        String cleanString = stringLength(plainText);
        int cols = Math.abs(this.getKey());
        int rows = cleanString.length() % Math.abs(key) == 0 ? Math.abs(cleanString.length()/Math.abs(key))
                        :cleanString.length()/Math.abs(key) + 1;
        char[][] grid = new char[rows][cols];
        int index = 0;
        for (int i = 0; i < rows;i++){
            for (int j = 0; j < cols; j++){
                if(index < cleanString.length()) {
                    grid[i][j] = cleanString.charAt(index);
                    index++;
                } else {
                    grid[i][j] = 'X';
                }
            }
        }
        int elements = rows*cols;
        String toReturn = "";
        if(key > 0) {
            toReturn = anticlockwiseTopSpiral(grid,0,0,rows-1,cols-1,elements);
        }
        else if(key < 0) {
            toReturn = anticlockwiseBottomSpiral(grid,rows-1,cols-1,0,0,elements);
        }
        return toReturn;
    }
    public String decrypt(String cipherText) {
        int cols = Math.abs(this.getKey());
        int rows = cipherText.length() % Math.abs(key) == 0 ? Math.abs(cipherText.length()/Math.abs(key))
                :cipherText.length()/Math.abs(key) + 1;
        char[][] grid = new char[rows][cols];
        int elements = cipherText.length();
        String toReturn = "";
        if(key > 0 ) {
            int index = 0;
            int startRow = 0;
            int startCol = 0;
            int endRow = rows - 1;
            int endCol = cols - 1;
            while(elements != 0 && index < cipherText.length()) {
                // Top to bottom direction
                for (int i = startRow; i <= endRow &&
                        elements > 0; ++i, elements--)
                {
                    grid[i][startRow] = cipherText.charAt(index);
                    index++;
                }

                // Left to right direction
                for (int i = startRow + 1; i <= endCol &&
                        elements > 0; ++i, elements--)
                {
                    grid[endRow][i] = cipherText.charAt(index);
                    index++;
                }
                // Bottom to top direction
                for (int i = endRow - 1; i > startRow &&
                        elements > 0; --i, elements--)
                {
                    grid[i][endCol] = cipherText.charAt(index);
                    index++;
                }
                // Right to left direction
                for (int i = endCol; i > startCol &&
                        elements > 0; --i, elements--)
                {
                    grid[startRow][i] = cipherText.charAt(index);
                    index++;
                }
                startRow ++;
                startCol++;
                endRow--;
                endCol--;
            }

            for (int i = 0; i < rows;i++){
                for (int j = 0; j < cols; j++){
                    toReturn += grid[i][j];
                }
            }
            index = 0;
        }

        else if( key < 0) {
            int index = 0;
            int startRow = 0;
            int startCol = 0;
            int endRow = rows - 1;
            int endCol = cols - 1;
            while(elements != 0 && index < cipherText.length()){
                // Bottom to top direction
                for (int i = startRow ; i >= endRow &&
                        elements > 0; --i, elements--)
                {
                    grid[i][startCol] = cipherText.charAt(index);
                    index++;
                }
                startCol--;

                // Right to left direction
                for (int i = startCol; i >= endCol &&
                        elements > 0; --i, elements--)
                {
                    grid[endRow][i] = cipherText.charAt(index);
                    index++;
                }
                endRow++;
                // Top to bottom direction
                for (int i = endRow; i <= startRow &&
                        elements > 0; ++i, elements--)
                {
                    grid[i][endCol] = cipherText.charAt(index);
                    index++;
                }
                endCol++;

                // Left to right direction
                for (int i = endCol; i <= startCol &&
                        elements > 0; ++i, elements--)
                {
                    grid[startRow][i] = cipherText.charAt(index);
                    index++;
                }
                startRow--;
            }

            for (int i = 0; i < rows;i++){
                for (int j = 0; j < cols; j++){
                    toReturn += grid[i][j];
                }
            }
            index = 0;
        }


        return toReturn;
    }

    @Override
    public String toString() {
        return "";
    }
}
