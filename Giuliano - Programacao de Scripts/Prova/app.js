class Produto {
    constructor (codFabricante, fabricante, descricao, valorCusto, valorVenda) {
        this.codFabricante = codFabricante;
        this.fabricante = fabricante;
        this.descricao = descricao;
        this.valorCusto = valorCusto;
        this.valorVenda = valorVenda;
    }
}

const app = new Vue({
    el: '#app',
    data: {
        produtoAtual: {
            codFabricante: '',
            fabricante: '',
            descricao: '',
            valorCusto: '',
            valorVenda: ''
        },
        produtos: [],
        modoEdicao: false,
        indexProduto: -1,
        labelBtn: 'Cadastrar'
    },
    computed: {
    },
    methods: {

        cadastraOuEditaProduto() {
            console.log(this.validaCampos());
        
            // Modo de inserção
            if (this.modoEdicao != true && this.indexProduto == -1) {
                const produto = new Produto(
                    this.produtoAtual.codFabricante,
                    this.produtoAtual.fabricante,
                    this.produtoAtual.descricao,
                    this.produtoAtual.valorCusto,
                    this.produtoAtual.valorVenda
                );
    
                this.produtos.push(produto);
    
                this.produtoAtual = {
                    codFabricante: '',
                    fabricante: '',
                    descricao: '',
                    valorCusto: '',
                    valorVenda: ''
                }

            // Modo de edição
            } else if (this.modoEdicao == true && this.indexProduto != -1) {
                this.produtos[this.indexProduto] = {
                    ...this.produtoAtual
                }

                this.produtoAtual = {
                    codFabricante: '',
                    fabricante: '',
                    descricao: '',
                    valorCusto: '',
                    valorVenda: ''
                }

                // Reseta valores para o padrão
                this.modoEdicao = false;
                this.indexProduto = -1;
                this.labelBtn = 'Cadastrar';
            }

        },
        habilitaModoEdicao(indexProduto) {
            // Apenas altera os valores para que a condição de edição seja possível
            this.modoEdicao = true;
            this.indexProduto = indexProduto;

            this.produtoAtual = {
                ...this.produtos[indexProduto]
            }

            this.labelBtn = 'Salvar';
        },
        removeProduto(indexProduto) {
            this.indexProduto = indexProduto;
            this.produtos.splice(this.indexProduto, 1);
            this.indexProduto = -1;
        },
        validaCampos() {
            // Sera chamada cada vez que algum dos v-models (inputs) abaixo for modificado
            return this.produtoAtual.codFabricante && this.produtoAtual.fabricante && this.produtoAtual.descricao
                    && this.produtoAtual.valorCusto && this.produtoAtual.valorVenda;
        },
        formataMoeda(valor) {
            if (!valor) {
                return 'R$ 0,00';
            }
            valor = parseFloat(valor);
            return valor.toLocaleString('pt-BR', {style: 'currency', currency: 'BRL'});
        }
    },
});