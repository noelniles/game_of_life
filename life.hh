const int MAXROW = 20;
const int MAXCOL = 60;


class Life {
    public:
        void initialize();
        void print();
        void update();
    private:
        int grid[MAXROW+2][MAXCOL+2]; // allows for sentinel rows and cols
        int neighbor_count(int row, int col);
};
