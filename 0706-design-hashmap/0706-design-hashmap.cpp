class MyHashMap {
    int arr[1000001];

public:
    MyHashMap() {
        fill(arr, arr + 1000001, -1);
    }

    void put(int key, int value) {
        arr[key] = value;
    }

    int get(int key) {
        return arr[key];
    }

    void remove(int key) {
        arr[key] = -1;
    }
};