import ColorTheme from "./MyColorContext"

const FunctionContextB = () => {
    return (
        <ColorTheme.Consumer>
            {
                (cores) => {
                    return (
                        <div>
                            <h1 style={{ backgroundColor: cores.bkgB }}>
                                Contexto B
                            </h1>
                        </div>
                    )
                }
            }
        </ColorTheme.Consumer>

    )
}

export default FunctionContextB