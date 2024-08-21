import React, { useState } from "react";

const Questao02 = () => {
  // Estado para alternar entre a imagem frontal e a traseira
  const [isFront, setIsFront] = useState(true);

  const frontImage = "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/25.png";
  const backImage = "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/back/25.png";

  // Função para alternar a imagem exibida
  const toggleImage = () => {
    setIsFront(!isFront);
  };

  // Redenrização do componente
  return (
    <div>
      <img src={isFront ? frontImage : backImage} alt="Pokemon" />
      <button onClick={toggleImage}>Alternar Imagem</button>
    </div>
  );
};

export default Questao02;