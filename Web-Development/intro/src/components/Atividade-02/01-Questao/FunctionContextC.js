import ColorTheme from "./MyColorContext"
import FunctionContextD from "./FunctionContextD"

const FunctionContextC = () => {
    return (
        <ColorTheme.Consumer>
            {
                (cores) => {
                    return (
                        <div>
                            <h1 style={{ backgroundColor: cores.bkgC }}>
                                Contexto C
                            </h1>
                            <FunctionContextD />
                        </div>
                    )
                }
            }
        </ColorTheme.Consumer>

    )
}

export default FunctionContextC