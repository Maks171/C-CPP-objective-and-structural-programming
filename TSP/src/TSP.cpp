#include "TSP.hpp"

#include <algorithm>
#include <stack>
#include <optional>


using cost_vec = std::vector<cost_t>;
using sorted_path_t = unsorted_path_t;

std::ostream& operator<<(std::ostream& os, const CostMatrix& cm) {
    for (std::size_t r = 0; r < cm.size(); ++r) {
        for (std::size_t c = 0; c < cm.size(); ++c) {
            const auto& elem = cm[r][c];
            os << (is_inf(elem) ? "INF" : std::to_string(elem)) << " ";
        }
        os << "\n";
    }
    os << std::endl;
    return os;
}

/* PART 1 */ //

/**
 * Create path from unsorted path and last 2x2 cost matrix.
 * @return The vector of consecutive vertex.
 */
path_t StageState::get_path() {
    reduce_cost_matrix();
    unsorted_path_t unsorted_path = get_unsorted_path();
    for (std::size_t row_index = 0; row_index < matrix_.size(); row_index++) {
        for (std::size_t col_index = 0; col_index < matrix_.size(); col_index++) {
            if (matrix_[row_index][col_index] == 0) {
                unsorted_path.push_back(vertex_t(row_index,col_index));
            }
        }
    }
    sorted_path_t sorted_path{unsorted_path[0]};

    while (sorted_path.size() < unsorted_path.size()){
        for (vertex_t vertex : unsorted_path)
            if (vertex.row==sorted_path.back().col)
                sorted_path.push_back(vertex);
    }
    path_t path;
    for (vertex_t vertex : sorted_path)
        path.push_back(vertex.row+1);
    return path;
}

/**
 * Get minimum values from each row and returns them.
 * @return Vector of minimum values in row.
 */
std::vector<cost_t> CostMatrix::get_min_values_in_rows() const {
    std::vector<cost_t> min_values;
    for (std::vector<int> row : matrix_) {
        cost_t act_min=row[0];
        for (cost_t value : row) {
            if (value < act_min)
                act_min = value;
        }
        if (is_inf(act_min))
            act_min=0;
        min_values.push_back(act_min);
    }
    return min_values;
}

/**
 * Reduce rows so that in each row at least one zero value is present.
 * @return Sum of values reduced in rows.
 */
cost_t CostMatrix::reduce_rows() {
    int reduced_sum=0;
    cost_vec row_mins = get_min_values_in_rows();
    for (size_t r_index = 0; r_index < matrix_.size(); r_index++) {
        for (size_t c_index = 0; c_index < matrix_[0].size(); c_index++) {
            if (matrix_[r_index][c_index]!=INF)
                matrix_[r_index][c_index]=matrix_[r_index][c_index] - row_mins[r_index];
        }
        reduced_sum+=row_mins[r_index];
    }
    return reduced_sum;
}

/**
 * Get minimum values from each column and returns them.
 * @return Vector of minimum values in columns.
 */
std::vector<cost_t> CostMatrix::get_min_values_in_cols() const {
    std::vector<cost_t> min_values;
    for (size_t col_index=0;col_index<matrix_[0].size();col_index++) {
        cost_t act_min=matrix_[0][col_index];
        for (const auto & val_index : matrix_) {
            if (val_index[col_index] < act_min)
                act_min = val_index[col_index];
        }
        if (is_inf(act_min))
            act_min=0;
        min_values.push_back(act_min);
    }
    return min_values;
}


/**
 * Reduces rows so that in each column at least one zero value is present.
 * @return Sum of values reduced in columns.
 */
cost_t CostMatrix::reduce_cols() {
    int reduced_sum=0;
    cost_vec cols_mins = get_min_values_in_cols();
    for (size_t c_index = 0; c_index < matrix_[0].size(); c_index++) {
        for (auto & r_index : matrix_) {
            if (r_index[c_index] != INF)
                r_index[c_index]=r_index[c_index] - cols_mins[c_index];
        }
        reduced_sum+=cols_mins[c_index];
    }
    return reduced_sum;
}


/**
 * Get the cost of not visiting the vertex_t (@see: get_new_vertex())
 * @param row
 * @param col
 * @return The sum of minimal values in row and col, excluding the intersection value.
 */
cost_t CostMatrix::get_vertex_cost(std::size_t row, std::size_t col) const {
    int min_row=INF,min_col=INF;
    for (size_t row_index=0;row_index<matrix_.size();row_index++){
        if ((row_index!=row) && (matrix_[row_index][col] < min_col))
            min_col=matrix_[row_index][col];
    }
    for (size_t col_index=0; col_index<matrix_[0].size();col_index++){
        if ((col_index!=col) && (matrix_[row][col_index]<min_row))
            min_row=matrix_[row][col_index];
    }
    return min_row+min_col;
}

/* PART 2 */

/**
 * Choose next vertex to visit:
 * - Look for vertex_t (pair row and column) with value 0 in the current cost matrix.
 * - Get the vertex_t cost (calls get_vertex_cost()).
 * - Choose the vertex_t with maximum cost and returns it.
 * @param cm
 * @return The coordinates of the next vertex.
 */
NewVertex StageState::choose_new_vertex() {
    CostMatrix cm = get_matrix();
    cost_t max_minsum =0;
    vertex_t max_vertex;
    for (size_t row_index = 0; row_index < cm.size(); row_index++) {
        for (size_t col_index = 0; col_index < cm[0].size(); col_index++)
            if (cm[row_index][col_index] == 0) {
                vertex_t vertex(row_index, col_index);
                cost_t cost = cm.get_vertex_cost(row_index, col_index);
                if (cost > max_minsum) {
                    max_vertex = vertex;
                    max_minsum = cost;
                }
            }
    }
    return NewVertex(max_vertex, max_minsum);
}
/**
 * Update the cost matrix with the new vertex.
 * @param new_vertex
 */
void StageState::update_cost_matrix(vertex_t new_vertex) {
    for (size_t row_index=0;row_index<matrix_.size();row_index++){
        if (row_index!=new_vertex.row)
            matrix_[row_index][new_vertex.col]=INF;
        else
            for (size_t column_index=0;column_index<matrix_[0].size();column_index++)
                matrix_[row_index][column_index]=INF;
    }

    if ((new_vertex.col < matrix_.size()) and (new_vertex.row < matrix_[0].size()))
        matrix_[new_vertex.col][new_vertex.row]=INF;

    unsorted_path_t actual_path = get_unsorted_path();
    size_t previous_path_size;
    for (vertex_t elem : unsorted_path_) {
        sorted_path_t test_sorted_path = {elem};


        do {
            previous_path_size = test_sorted_path.size();
            for (vertex_t vertex : unsorted_path_) {
                if (vertex.row == test_sorted_path.back().col) {
                    test_sorted_path.push_back(vertex);
                    matrix_[test_sorted_path[0].row][test_sorted_path.back().col] = INF;
                    matrix_[test_sorted_path.back().col][test_sorted_path[0].row] = INF;
                }
                if (vertex.col == test_sorted_path[0].row) {
                    test_sorted_path.insert(test_sorted_path.begin(), vertex);
                    matrix_[test_sorted_path[0].row][test_sorted_path.back().col] = INF;
                    matrix_[test_sorted_path.back().col][test_sorted_path[0].row] = INF;
                }
            }
        } while (previous_path_size != test_sorted_path.size());
    }
}

/**
 * Reduce the cost matrix.
 * @return The sum of reduced values.
 */
cost_t StageState::reduce_cost_matrix() {
    cost_t sum = 0;
    sum += matrix_.reduce_rows();
    sum += matrix_.reduce_cols();
    return sum;

}

/**
 * Given the optimal path, return the optimal cost.
 * @param optimal_path
 * @param m
 * @return Cost of the path.
 */
/**
 * Given the optimal path, return the optimal cost.
 * @param optimal_path
 * @param m
 * @return Cost of the path.
 */
cost_t get_optimal_cost(const path_t& optimal_path, const cost_matrix_t& m) {
    cost_t cost = 0;

    for (std::size_t idx = 1; idx < optimal_path.size(); ++idx) {
        cost += m[optimal_path[idx - 1] - 1][optimal_path[idx] - 1];
    }

    // Add the cost of returning from the last city to the initial one.
    cost += m[optimal_path[optimal_path.size() - 1] - 1][optimal_path[0] - 1];

    return cost;
}

/**
 * Create the right branch matrix with the chosen vertex forbidden and the new lower bound.
 * @param m
 * @param v
 * @param lb
 * @return New branch.
 */
StageState create_right_branch_matrix(cost_matrix_t m, vertex_t v, cost_t lb) {
    CostMatrix cm(m);
    cm[v.row][v.col] = INF;
    return StageState(cm, {}, lb);
}

/**
 * Retain only optimal ones (from all possible ones).
 * @param solutions
 * @return Vector of optimal solutions.
 */
tsp_solutions_t filter_solutions(tsp_solutions_t solutions) {
    cost_t optimal_cost = INF;
    for (const auto& s : solutions) {
        optimal_cost = (s.lower_bound < optimal_cost) ? s.lower_bound : optimal_cost;
    }

    tsp_solutions_t optimal_solutions;
    std::copy_if(solutions.begin(), solutions.end(),
                 std::back_inserter(optimal_solutions),
                 [&optimal_cost](const tsp_solution_t& s) { return s.lower_bound == optimal_cost; }
    );

    return optimal_solutions;
}

/**
 * Solve the TSP.
 * @param cm The cost matrix.
 * @return A list of optimal solutions.
 */
tsp_solutions_t solve_tsp(const cost_matrix_t& cm) {

    StageState left_branch(cm);

    // The branch & bound tree.
    std::stack<StageState> tree_lifo;

    // The number of levels determines the number of steps before obtaining
    // a 2x2 matrix.
    std::size_t n_levels = cm.size() - 2;

    tree_lifo.push(left_branch);   // Use the first cost matrix as the root.

    cost_t best_lb = INF;
    tsp_solutions_t solutions;

    while (!tree_lifo.empty()) {

        left_branch = tree_lifo.top();
        tree_lifo.pop();
        while (left_branch.get_level() != n_levels && left_branch.get_lower_bound() <= best_lb) {
            // Repeat until a 2x2 matrix is obtained or the lower bound is too high...
            if (left_branch.get_level() == 0) {
                left_branch.reset_lower_bound();
            }

            // 1. Reduce the matrix in rows and columns.
            cost_t new_cost = left_branch.reduce_cost_matrix();

            // 2. Update the lower bound and check the break condition.
            left_branch.update_lower_bound(new_cost);
            if (left_branch.get_lower_bound() > best_lb) {
                break;
            }

            // 3. Get new vertex and the cost of not choosing it.
            NewVertex new_vertex = left_branch.choose_new_vertex();

            // 4. Update the path - use append_to_path method.
            left_branch.append_to_path(new_vertex.coordinates);

            // 5. Update the cost matrix of the left branch.
            left_branch.update_cost_matrix(new_vertex.coordinates);

            // 6. Update the right branch and push it to the LIFO.
            cost_t new_lower_bound = left_branch.get_lower_bound() + new_vertex.cost;
            tree_lifo.push(create_right_branch_matrix(cm, new_vertex.coordinates,
                                                      new_lower_bound));
        }

        if (left_branch.get_lower_bound() <= best_lb) {
            // If the new solution is at least as good as the previous one,
            // save its lower bound and its path.
            best_lb = left_branch.get_lower_bound();
            path_t new_path = left_branch.get_path();
            solutions.push_back({get_optimal_cost(new_path, cm), new_path});
        }
    }

    return filter_solutions(solutions); // Filter solutions to find only optimal ones.
}
