/* Function to estimate pi using the Leibniz formula */
function estimatePi (terms) {
  if (terms <= 0) {
    return 0.0
  }

  let numerator = -1.0
  let pi = 0.0

  for (let i = 0; i < terms; i++) { // loop from 0 to terms-1
    numerator *= -1
    const denominator = 2 * i + 1
    pi += numerator / denominator
  }

  return 4 * pi
}

/* Function to test the estimatePi() function */
function testEstimatePi () {
  const vals = [-1, 0, 1, 2, 10, 100]
  for (let i = 0; i < vals.length; i++) {
    console.log(vals[i] + ' ' + estimatePi(vals[i]))
  }
}

testEstimatePi()
