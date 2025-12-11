# Function to estimate pi using a given number of terms
def estimatePi(terms):
    if terms <= 0:
        return 0.0  # handle bad inputs
    numerator = -1.0
    total = 0.0
    for i in range(terms):  # loop from 0 to terms-1
        numerator *= -1
        denominator = 2 * i + 1
        total += numerator / denominator
    return 4 * total


# Test the estimatePi() function
def testEstimatePi():
    vals = [-1, 0, 1, 2, 10, 100]
    for n in vals:
        print(n, estimatePi(n))


if __name__ == "__main__":
    testEstimatePi()
