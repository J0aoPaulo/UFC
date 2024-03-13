const FuncoesInternas  = () => {

    let num1 = 15
    let num2 = 10


    const sum = (num1, num2) => num1 + num2
    const subtract = (x, y) => x - y


    return (
        <div>
            <h1>Calculator</h1>
            <h2>this is the sum: {sum(num1, num2)} </h2>
            <h3>and this is the subtract: {subtract(num1, num2)}</h3>
        </div>
    )
}

export default FuncoesInternas