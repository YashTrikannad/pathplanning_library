//
// Created by yash on 8/4/19.
//

#pragma once

#include <Eigen/Core>
#include <opencv2/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <vector>

namespace pl::common
{

template<typename ElementType>
void print_2d_vector(const std::vector<std::vector<ElementType>> &container)
{
    for (const auto &vector:container)
    {
        for (const auto &element:vector)
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
}

template <typename Graph>
void display(const Graph& graph)
{
    using namespace cv;
    Mat image;
    eigen2cv(graph, image);
    imshow( "Current Graph", image );
    waitKey(0);
}

template <typename Graph, typename Path>
void display(Graph& graph, const Path& path)
{
    using namespace cv;
    Mat image;
    for(const auto& node:path)
    {
        graph(node.row_index_, node.column_index_) = 0.5;
    }

    eigen2cv(graph, image);

    imshow( "Current Graph", image );
    waitKey(0);
}

} // namespace pl::common