/*
 * Copyright (C) 2016-2019 Istituto Italiano di Tecnologia (IIT)
 *
 * This software may be modified and distributed under the terms of the
 * BSD 3-Clause license. See the accompanying LICENSE file for details.
 */

#include <iostream>
#include <thread>

#include <BayesFilters/directional_statistics.h>

using namespace bfl;
using namespace bfl::directional_statistics;
using namespace Eigen;


int main()
{
    std::cout << "Running directional add...\n" << std::endl;


    std::cout << "With Vector3d:\n" << std::endl;

    Vector3d angle_d_a(1.0, 2.0, 3.0);
    Vector3d angle_d_b(1.0, 2.0, 3.0);

    Vector3d angle_d_result = directional_add(angle_d_a, angle_d_b);

    std::cout << "Vector a:\n" << angle_d_a << "\nVector b:\n" << angle_d_b << "\nResult:\n" << angle_d_result << "\n" << std::endl;

    if (!(((angle_d_result(0) -  2.0     ) < 0.00001) &&
          ((angle_d_result(1) - -2.28319 ) < 0.00001) &&
          ((angle_d_result(2) - -0.283185) < 0.00001)   ))
    {
        std::cerr << "Directional add produced wrong results, should be (2.0, -2.28319, -0.283185)." << std::endl;
        return EXIT_FAILURE;
    }
    else
        std::cout << "Directional add produced correct results.\n" << std::endl;


    std::cout << "...done!\n" << std::endl;



    std::cout << "Running directional sub...\n" << std::endl;


    std::cout << "With Vector3d:\n" << std::endl;

    angle_d_a << 1.0,  2.0,  3.0;
    angle_d_b << 1.0, -2.0, -3.0;

    angle_d_result = directional_sub(angle_d_a, angle_d_b);

    std::cout << "Vector a:\n" << angle_d_a << "\nVector b:\n" << angle_d_b << "\nResult:\n" << angle_d_result << "\n" << std::endl;

    if (!(((angle_d_result(0) -  0       ) < 0.00001) &&
          ((angle_d_result(1) - -2.28319 ) < 0.00001) &&
          ((angle_d_result(2) - -0.283185) < 0.00001)   ))
    {
        std::cerr << "Directional sub produced wrong results, should be (2.0, -2.28319, -0.283185)." << std::endl;
        return EXIT_FAILURE;
    }
    else
        std::cout << "Directional sub produced correct results.\n" << std::endl;


    std::cout << "...done!\n" << std::endl;



    std::cout << "Running directional mean...\n" << std::endl;


    std::cout << "With 1 column:\n" << std::endl;
    {
        MatrixXd angle_d_mean(2, 1);
        angle_d_mean << 3.14,
                        1.57;
        VectorXd angle_d_weights(1);
        angle_d_weights << 0.0;

        Vector2d d_mean = directional_mean(angle_d_mean, angle_d_weights);

        std::cout << "Matrix a:\n" << angle_d_mean << "\nVector w:\n" << angle_d_weights << "\nResult:\n" << d_mean << "\n" << std::endl;

        if (!(((d_mean(0) -  3.14) < 0.01) && ((d_mean(1) -  1.57) < 0.01)))
        {
            std::cerr << "Directional mean produced wrong results." << std::endl;
            return EXIT_FAILURE;
        }
        else
            std::cout << "Directional mean produced correct results.\n" << std::endl;
    }

    std::cout << "With 2 columns:\n" << std::endl;
    {
        Matrix2d angle_d_mean;
        angle_d_mean << 3.14, -3.14,
                        1.57, -1.57;
        Vector2d angle_d_weights(0.5, 0.5);

        Vector2d d_mean = directional_mean(angle_d_mean, angle_d_weights);

        std::cout << "Matrix a:\n" << angle_d_mean << "\nVector w:\n" << angle_d_weights << "\nResult:\n" << d_mean << "\n" << std::endl;

        if (!(((d_mean(0) -  3.14) < 0.01) && ((d_mean(1) -  0.0) < 0.01)))
        {
            std::cerr << "Directional mean produced wrong results." << std::endl;
            return EXIT_FAILURE;
        }
        else
            std::cout << "Directional mean produced correct results.\n" << std::endl;
    }
    std::cout << "...done!\n" << std::endl;


    return EXIT_SUCCESS;
}
