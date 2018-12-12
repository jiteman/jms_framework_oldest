/////////////////////////////////////////////////////////////////////////////////////
// EARandomDistribution.h
//
// Copyright (c) 2007 Criterion Software Limited and its licensors. All Rights Reserved.
// Created by Paul Pedriana.
//
// This file implements a basic set of random number generators suitable for game
// development usage.
/////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
// This code includes basic random number generator functionality. It is good for
// most game development uses with the exception of cryptographic uses and legally 
// controlled gambling mechanisms. For example, cryptographic random number generator 
// requirements have additional considerations regarding protection against 
// cryptographic attacks.
//
// There are many free C/C++ random number packages available today. Many of them 
// are rather comprehensive and some are fairly flexible. The design of this package
// is based on the needs of game programmers and intentionally avoids some of the 
// complications of other packages. This package is designed first and foremost to 
// be fast and to offer at least the option of low footprint. Secondly this package
// is designed to be very easily understood with a minimum of effort; experience has
// shown that game programmers will not use a library unless they can figure it out 
// on their own in a matter of a few minutes. This last consideration rules out the 
// possibility of using a heavily templated library such as that found in Boost.
//
// Functions:
//     bool     RandomBool(Random& r);
//     int32_t  Random2(Random& r);
//     int32_t  Random4(Random& r);
//     int32_t  Random8(Random& r);
//     int32_t  Random16(Random& r);
//     int32_t  Random32(Random& r);
//     int32_t  Random64(Random& r);
//     int32_t  Random128(Random& r);
//     int32_t  Random256(Random& r);
//     int32_t  RandomPowerOfTwo(Random& r, unsigned nPowerOfTwo);
//     int32_t  RandomInt32UniformRange(Random& r, int32_t nBegin, int32_t nEnd);
//     double   RandomDoubleUniformRange(Random& r, double begin, double end);
//     uint32_t RandomUint32WeightedChoice(Random& r, uint32_t nLimit, float weights[]);
//     int32_t  RandomInt32GaussianRange(Random& r, int32_t nBegin, int32_t nEnd);
//     Float    RandomFloatGaussianRange(Random& r, Float fBegin, Float fEnd);
//     int32_t  RandomInt32TriangleRange(Random& r, int32_t nBegin, int32_t nEnd);
//     Float    RandomFloatTriangleRange(Random& r, Float fBegin, Float fEnd);
//
/////////////////////////////////////////////////////////////////////////////////////


#ifndef EASTDC_EARANDOMDISTRIBUTION_H
#define EASTDC_EARANDOMDISTRIBUTION_H


#include "EA/StdC/internal/Config.h"
#include "EA/StdC/EAFixedPoint.h"
#include "EA/StdC/EARandom.h"


namespace EA
{
namespace StdC
{

    // Distribution adapters
    
    /// RandomBool
    /// Returns true or false.
    template <typename Random>
    bool RandomBool(Random& r)
    {
        return (r.RandomUint32Uniform() & 0x80000000) != 0;
    } 


    /// Random2
    /// Returns a value between 0 and 1, inclusively.
    template <typename Random>
    int32_t Random2(Random& r)
    {  // Don't trust the low bits, as some generators don't have good low bits.
        return (int32_t)(r.RandomUint32Uniform() >> 31);
    } 


    /// Random4
    /// Returns a value between 0 and 3, inclusively.
    template <typename Random>
    int32_t Random4(Random& r)
    {
        return (int32_t)(r.RandomUint32Uniform() >> 30);
    } 


    /// Random8
    /// Returns a value between 0 and 7, inclusively.
    template <typename Random>
    int32_t Random8(Random& r)
    {
        return (int32_t)(r.RandomUint32Uniform() >> 29);
    } 


    /// Random16
    /// Returns a value between 0 and 15, inclusively.
    template <typename Random>
    int32_t Random16(Random& r)
    {
        return (int32_t)(r.RandomUint32Uniform() >> 28);
    } 


    /// Random32
    /// Returns a value between 0 and 31, inclusively.
    template <typename Random>
    int32_t Random32(Random& r)
    {
        return (int32_t)(r.RandomUint32Uniform() >> 27);
    } 


    /// Random64
    /// Returns a value between 0 and 63, inclusively.
    template <typename Random>
    int32_t Random64(Random& r)
    {
        return (int32_t)(r.RandomUint32Uniform() >> 26);
    } 


    /// Random128
    /// Returns a value between 0 and 127, inclusively.
    template <typename Random>
    int32_t Random128(Random& r)
    {
        return (int32_t)(r.RandomUint32Uniform() >> 25);
    } 


    /// Random256
    /// Returns a value between 0 and 255, inclusively.
    template <typename Random>
    int32_t Random256(Random& r)
    {
        return (int32_t)(r.RandomUint32Uniform() >> 24);
    } 


    /// RandomPowerOfTwo
    /// Returns a value between 0 and 2 ^ nPowerOfTwo - 1, inclusively. 
    /// This is a generalized form of the RandomN set of functions.
    template <typename Random>
    int32_t RandomPowerOfTwo(Random& r, unsigned nPowerOfTwo)
    {
        //assert(nPowerOfTwo <= 32);
        return (int32_t)(r.RandomUint32Uniform() >> (32 - nPowerOfTwo));
    } 


    /// RandomInt32UniformRange
    /// Return value is from nBegin to nEnd-1 inclusively, with uniform probability.
    template <typename Random>
    int32_t RandomInt32UniformRange(Random& r, int32_t nBegin, int32_t nEnd)
    {
        return nBegin + (int32_t)r.RandomUint32Uniform((uint32_t)(nEnd - nBegin));
    }


    /// RandomDoubleUniformRange
    /// Return value is in range of [nBegin, nEnd) with uniform probability.
    template <typename Random>
    double RandomDoubleUniformRange(Random& r, double begin, double end)
    {
        const double result = begin + r.RandomDoubleUniform(end - begin);

        if(result >= end)   // FPU roundoff errors can cause the result to 
            return end;     // go slightly outside the range. We deal with 
        if(result < begin)  // the possibility of this.
            return begin;
        return result;
    }


    /// RandomUint32WeightedChoice
    ///
    /// Return value is from 0 to nLimit-1 inclusively, with probabilities proportional to weights.
    /// The input array weights must be of length <nLimit>. These values are used to 
    /// determine the probability of each choice. That is, weight[i] is proportional 
    /// to the probability that this function will return i. Negative values are ignored. 
    /// This function is useful in generating a custom distribution.
    ///
    /// Example usage:
    ///    const float weights[7] = { 128, 64, 32, 16, 8, 4, 2 };  // Create a logarithmic distribution in the range of [0, 6).
    ///
    ///    uint32_t x = RandomUint32WeightedChoice(random, 7, weights);
    ///
    template <typename Random>
    uint32_t RandomUint32WeightedChoice(Random& r, uint32_t nLimit, const float weights[])
    {
        if(nLimit >= 2)
        {
            float weightSum = 0;

            for(uint32_t i = 0; i < nLimit; ++i)
            {
                const float weight = weights[i];

                if(weight > 0)
                    weightSum += weight;
            }

            if(weightSum > 0)
            {
                float value = (float)RandomDoubleUniformRange(r, 0, weightSum);

                // Do a linear search. A binary search would be faster for 
                // cases where the array size is > ~10.
                for(uint32_t j = 0; j < nLimit; ++j)
                {
                    const float weight = weights[j];

                    if(weight > 0)
                    {
                        if(value < weight)
                            return j;
                        value -= weight;
                    }
                }
            }
            else
                return r.RandomUint32Uniform(nLimit);
        }

        // Normally we shouldn't get here, but we might due to rounding errors.
        return nLimit - 1;
    }




    /// RandomInt32GaussianRange
    ///
    ///  Creates an approximation to a normal distribution (a.k.a. "Gaussian", 
    ///  "bell-curve") in the range of [nBegin, nEnd).
    ///
    ///         |                                       
    ///         |                ****                   
    ///         |              *      *                 
    ///         |             *        *                
    ///         |            *          *               
    ///         |           *            *              
    ///         |          *              *             
    ///         |         *                *            
    ///         |        *                  *           
    ///         |    * *                      * *       
    ///         ----------------------------------------
    ///              |                          |
    ///            begin                       end
    ///
    template <typename Random>
    int32_t RandomInt32GaussianRange(Random& r, int32_t nBegin, int32_t nEnd)
    {
        const uint32_t t0     = r.RandomUint32Uniform();
        const uint32_t t1     = r.RandomUint32Uniform();
        const uint32_t t2     = r.RandomUint32Uniform();
        const uint32_t t3     = r.RandomUint32Uniform();
        const uint64_t tcubic = ((((uint64_t)t0 + t1) + ((uint64_t)t2 + t3) + 2) >> 2);

        return nBegin + (int32_t)((tcubic * (uint32_t)(nEnd - nBegin)) >> 32);
    }


    /// RandomFloatGaussianRange
    ///
    /// Generates a floating point value with an approximated 
    /// Guassian distribution in the range of [fBegin, fEnd).
    ///
    /// Example usage:
    ///    float x = RandomFloatGaussianRange(random, 0.f, 100.f);
    ///
    template <typename Random, typename Float>
    Float RandomFloatGaussianRange(Random& r, Float fBegin, Float fEnd)
    {
        const Float x0 = (Float)r.RandomDoubleUniform();
        const Float x1 = (Float)r.RandomDoubleUniform();
        const Float x2 = (Float)r.RandomDoubleUniform();

        return fBegin + ((fEnd - fBegin) * Float(0.33333333) * (x0 + x1 + x2));
    }



    /// RandomInt32TriangleRange
    ///
    /// Creates a "triangle" distribution in the range of [nBegin, nEnd).
    ///
    ///         |                                     
    ///         |                *                    
    ///         |                                     
    ///         |             *     *                 
    ///         |                                     
    ///         |          *           *              
    ///         |                                     
    ///         |       *                 *           
    ///         |                                     
    ///         |    *                       *        
    ///         --------------------------------------
    ///              |                       |
    ///            begin                    end
    ///
    template <typename Random>
    int32_t RandomInt32TriangleRange(Random& r, int32_t nBegin, int32_t nEnd)
    {
        const uint32_t t0   = r.RandomUint32Uniform(); 
        const uint32_t t1   = r.RandomUint32Uniform();
        const uint64_t ttri = (t0 >> 1) + (t1 >> 1) + (t0 & t1 & 1); // triangular from 0...2^31-1

        return nBegin + (int32_t)((ttri * (uint32_t)(nEnd - nBegin)) >> 32);
    }


    /// RandomFloatTriangleRange
    ///
    /// Generates a floating point value with a triangular distribution 
    /// in the range of [fBegin, fEnd).
    ///
    /// Example usage:
    ///    double x = RandomFloatTriangleRange(random, 0.0, 100.0);
    ///
    template <typename Random, typename Float>
    Float RandomFloatTriangleRange(Random& r, Float fBegin, Float fEnd)
    {
        const Float u0 = (Float)r.RandomDoubleUniform();
        const Float u1 = (Float)r.RandomDoubleUniform();

        return fBegin + (fEnd - fBegin) * Float(0.5) * (u0 + u1);
    }


} // namespace StdC
} // namespace EA



#endif // Header include guard

























