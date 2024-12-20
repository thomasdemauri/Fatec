class Produto {
    constructor (codFabricante, fabricante, descricao, valorCusto, valorVenda, estoque) {
        this.codFabricante = codFabricante;
        this.fabricante = fabricante;
        this.descricao = descricao;
        this.valorCusto = valorCusto;
        this.valorVenda = valorVenda;
        this.estoque = estoque;
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
            valorVenda: '',
            estoque: ''
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
                    this.produtoAtual.valorVenda,
                    this.produtoAtual.estoque
                );
    
                this.produtos.push(produto);
    
                this.produtoAtual = {
                    codFabricante: '',
                    fabricante: '',
                    descricao: '',
                    valorCusto: '',
                    valorVenda: '',
                    estoque: ''
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
                    valorVenda: '',
                    estoque: ''
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
            if (confirm("Deseja realmente excluir o produto?")) {
                this.indexProduto = indexProduto;
                this.produtos.splice(this.indexProduto, 1);
                this.indexProduto = -1;
            }
        },
        validaCampos() {
            // Sera chamada cada vez que algum dos v-models (inputs) abaixo for modificado
            return this.produtoAtual.codFabricante && this.produtoAtual.fabricante && this.produtoAtual.descricao
                    && this.produtoAtual.valorCusto && this.produtoAtual.valorVenda && this.produtoAtual.estoque;
        },
        habilitaAcoes() {   
            // Responsavel por habilitar/desabilitar os botoes se estiver em modo de edicao
            return this.modoEdicao;
        },
        formataMoeda(valor) {
            if (!valor) {
                return 'R$ 0,00';
            }
            valor = parseFloat(valor);
            return valor.toLocaleString('pt-BR', {style: 'currency', currency: 'BRL'});
        },
        formataUnidade(valor) {
            if (!valor) {
                return '0,00';
            }
            return  `${valor} Unidades`;
        },
        custoEstoque() {
            return this.produtos.reduce((acc, produto, ) => {
                return acc + (parseFloat(produto.valorCusto || 0) * produto.estoque);
            }, 0);
        },
        vendaEstoque() {
            return this.produtos.reduce((acc, produto) => {
                return acc + (parseFloat(produto.valorVenda || 0) * produto.estoque);
            }, 0);
        },
        saldoEstoque() {
            venda = this.vendaEstoque();
            custo = this.custoEstoque();
            return venda - custo;
        }
    },
});