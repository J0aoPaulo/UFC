import React, { useEffect, useState } from "react";

const Questao04 = () => {
  // Armazenamento das capitais com maior e menor população
  const [maiorPopulacao, setMaiorPopulacao] = useState(null);
  const [menorPopulacao, setMenorPopulacao] = useState(null);

  const data = [
    {"capital":["Dublin"],"population":4994724},
    {"capital":["Nicosia"],"population":1207361},
    {"capital":["Madrid"],"population":47351567}
  ];

  // Função assíncrona para buscar os dados da Promise
  const fetchData = async () => {
    try {
      const dataPromise = new Promise((resolve) => {
        resolve(data);
      });

      const dataResolved = await dataPromise;

      let maior = dataResolved[0];
      let menor = dataResolved[0];

      dataResolved.forEach(country => {
        if (country.population > maior.population) {
          maior = country;
        }
        if (country.population < menor.population) {
          menor = country;
        }
      });

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

export default Questao04;