#ifndef RANDOM
#define RANDOM

double nextUniform() {
    double Uniform = rand() / double(RAND_MAX);
    return Uniform;
}

double nextGaussian() {

    static bool hasNextGaussian = false;
    static double nextNextGaussian;
    double v1, v2, s;

    if (!hasNextGaussian) {

        do {

            v1 = 2 * nextUniform() - 1;   // between -1.0 and 1.0
            v2 = 2 * nextUniform() - 1;   // between -1.0 and 1.0
            s = v1 * v1 + v2 * v2;

        } while (s >= 1 || s == 0);

        double multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        hasNextGaussian = true;
        return v1 * multiplier;

    } else {

        hasNextGaussian = false;
        return nextNextGaussian;

    }

}

#endif // RANDOM

