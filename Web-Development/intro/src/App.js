//import Pai from "./components/Atividade01/Questao01/01Pai";
//import * as PC from "./components/Atividade01/02MeuPc";
import * as Game from './components/Atividade01/03Batalha'

function App() {
  return (
    <div>
      {/*<Pai></Pai>*/}

      {/*
      <PC.PlacaMae nome="b550M" preco={1569.45.toFixed(2)}/>
      <PC.Memoria nome="Asgard 3600mhz" preco={600.00.toFgixed(2)}/>
      <PC.PlacaDeVideo nome="RTX 2060 Super" preco={1800.00.toFixed(2)}/>
      */}

      <Game.World>
        <Game.Arena name="Soul Society"/>
      </Game.World>
      
    </div>
  );
}

export default App;