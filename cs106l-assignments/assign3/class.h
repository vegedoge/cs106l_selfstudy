class DynamicArray {
    public:
        DynamicArray(int size);
        ~DynamicArray();
        void setSquaredIndices();
        void displayElements();

      private:
        int *_data;
        int _size;
};