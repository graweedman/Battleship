#define GRID_SIZE 256
#define GRID_WIDTH 16
#define GRID_HEIGHT 16

class Grid {
        bool grid[GRID_SIZE];
        int width = GRID_WIDTH;
        int height = GRID_HEIGHT;

        int get_index(int row, int col);
    public:
        Grid(int w, int h);

        void set_field(int row, int col);

        void reset_field(int row, int col);

        bool get_field(int row, int col);
};