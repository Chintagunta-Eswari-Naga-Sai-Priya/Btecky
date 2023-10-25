// Function to heapify a subtree rooted at a given index
void heapify(std::vector<int>& arr, int n, int root) {
    int largest = root; // Initialize the largest as the root
    int left = 2 * root + 1; // Left child
    int right = 2 * root + 2; // Right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != root) {
        std::swap(arr[root], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build a max heap (rearrange the array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
