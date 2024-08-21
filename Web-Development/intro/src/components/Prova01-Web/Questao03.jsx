import React, { useEffect, useState } from "react";

const Questao03 = () => {
  // Armazenamento das capitais com maior e menor população
  const [maiorPopulacao, setMaiorPopulacao] = useState(null);
  const [menorPopulacao, setMenorPopulacao] = useState(null);

  // Função assíncrona para buscar os dados
  const fetchData = async () => {
    try {
      const response = await fetch("https://restcountries.com/v3.1/region/europe?fields=capital,population");
      const data = await response.json();

      let maior = data[0];
      let menor = data[0];

      data.forEach(country => {
        if (country.population > maior.population) {
          maior = country;
        }
        if (country.population < menor.population) {
          menor = country;
        }
      });

      // Atualizando os estados com as capitais encontradas
      setMaiorPopulacao(maior);
      setMenorPopulacao(menor);
    } catch (error) {
      console.error("Erro ao buscar dados:", error);
    }
  };

  // Usando useEffect para buscar os dados quando o componente for montado
  useEffect(() => {
    fetchData();
  }, []);

  return (
    <div>
      <h1>Capitais com Maior e Menor População</h1>
      {maiorPopulacao && (
        <p>Maior População: {maiorPopulacao.capital[0]} - {maiorPopulacao.population}</p>
      )}
      {menorPopulacao && (
        <p>Menor População: {menorPopulacao.capital[0]} - {menorPopulacao.population}</p>
      )}
    </div>
  );
};

export default Questao03;