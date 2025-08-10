import { jsx as _jsx } from "react/jsx-runtime";

// Searching
import LinearSearch from "./pages/searching/Linear_Search";
import BinarySearch from "./pages/searching/Binary_Search";

// Sorting
import BubbleSort from "./pages/sorting/Bubble_Sort";
import CountingSort from "./pages/sorting/Counting_Sort";
import HeapSort from "./pages/sorting/Heap_Sort";
import MergeSort from "./pages/sorting/Merge_Sort";
import QuickSort from "./pages/sorting/Quick_Sort";
import SelectionSort from "./pages/sorting/Selection_Sort";
import RadixSort from "./pages/sorting/Radix_Sort";
import InsertionSort from "./pages/sorting/Insertion_Sort";

// Graph
import BFS from "./pages/graph/BFS_Search";
import DFS from "./pages/graph/DFS_Search";
import Dijkstra from "./pages/graph/Dijkstra";

const routes = [
  {
    id: 1,
    path: "/linear-search",
    element: _jsx(LinearSearch, {}),
    name: "Linear Search",
  },
  {
    id: 2,
    path: "/binary-search",
    element: _jsx(BinarySearch, {}),
    name: "Binary Search",
  },
  {
    id: 3,
    path: "/bubble-sort",
    element: _jsx(BubbleSort, {}),
    name: "Bubble Sort",
  },
  {
    id: 4,
    path: "/counting-sort",
    element: _jsx(CountingSort, {}),
    name: "Counting Sort",
  },
  {
    id: 5,
    path: "/heap-sort",
    element: _jsx(HeapSort, {}),
    name: "Heap Sort",
  },
  {
    id: 6,
    path: "/insertion-sort",
    element: _jsx(InsertionSort, {}),
    name: "Insertion Sort",
  },
  {
    id: 7,
    path: "/merge-sort",
    element: _jsx(MergeSort, {}),
    name: "Merge Sort",
  },
  {
    id: 9,
    path: "/quick-sort",
    element: _jsx(QuickSort, {}),
    name: "Quick Sort",
  },
  {
    id: 10,
    path: "radix-sort",
    element: _jsx(RadixSort, {}),
    name: "Radix Sort",
  },
  {
    id: 11,
    path: "/selection-sort",
    element: _jsx(SelectionSort, {}),
    name: "Selection Sort",
  },
  {
    id: 12,
    path: "/bfs-search",
    element: _jsx(BFS, {}),
    name: "Breadth First Search",
  },
  {
    id: 13,
    path: "/dfs-search",
    element: _jsx(DFS, {}),
    name: "Depth First Search",
  },
  {
    id: 14,
    path: "/dijkstra",
    element: _jsx(Dijkstra, {}),
    name: "Dijkstra",
  }
];

export default routes;
