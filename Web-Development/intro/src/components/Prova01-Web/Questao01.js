import React from "react";

const Questao01A = () => {

    const lista = [
        { a:10, b:3, c:7},
        { a:5, b:-3, c:9},
        { a:1, b:9, c:40}
    ];

    // Renderizando o componente Questao01B e passando a lista como props
    return (
        <div>
            <Questao01B lista={lista} />
        </div>
    );
};

function Questao01B(props) {
    // Desestruturando a lista das props
    const { lista } = props;    
    // Encontrando o maior valor de cada objeto na lista
    const maiorValor = lista.map(obj => Math.max(obj.a, obj.b, obj.c));

    // Renderizando os maiores valores
    return (
        <div>
        {maioresValores.map((valor, index) => (
        <p key={index}>Maior valor {index + 1}: {valor}</p>
      ))}
    </div>
  );
}

export default Questao01A;