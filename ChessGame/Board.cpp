#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    setAcceptDrops(true);//Aceptar drops
    BoardIcon.load(":/resources/Icons/ChessBoard.jpg"); //Cargar el icono del tablero

    reina = std::make_unique<Reina>(this);
    reina->move(0,0);
    //pieza->setText("Peon");

    reina->show();


}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *) //Para visualizar
{
    QPainter painter(this); //El que sabe pintar
    painter.drawPixmap(0,0,360,360, BoardIcon); //Entregar a painter donde va a dibujar el tablero
}

void Board::mousePressEvent(QMouseEvent *event)
{
    auto child  = childAt(event->pos());
    if(child == nullptr)
    {
        std::cout<<"null\n";
        return;
    }
        std::cout<<"child\n";

    QByteArray data; //Mandar al SO
    QDataStream dataStream(&data, QIODevice::WriteOnly);//Almacenar en data
    dataStream << QPoint(event->pos() - child->pos()); //Encapsular posicion desde se hizo clic

    QMimeData *mimeData = new QMimeData(); //Manera de enviar datos
    mimeData->setData("application/x-dnditemdata", data);//Encapsulando lo que necesitamos para hacer el drag and drop "standard"

    QDrag * drag = new QDrag(this);//Necesita donde va hacer la operacion de drag
    drag->setMimeData(mimeData); //Rescatar informacion al arrastrar el objeto

    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);//Ejecutar drag

}

void Board::dragMoveEvent(QDragMoveEvent *event)//Casi nunca cambia
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source() == this) //Verificar si estamos en el tablero
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();//Acepta el evento pero lo anula proque esta fuera del tablero
        }
    }
    else
    {
        event->ignore();
    }
}

void Board::dragEnterEvent(QDragEnterEvent *event) //Verificar si estoy dentro de mi widget
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source() == this) //Verificar sis estamos en el tablero
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void Board::dropEvent(QDropEvent *event)
{
    //mover la pieza, pero hay que controlar:
    //si es que lo que recibono está pérdido
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))//Volver a verificar si tiene la misma cara
    {
        QByteArray data = event->mimeData()->data("application/x-dnditemdata");//Recibimos la Posicion inicial
        QDataStream dataStream(&data, QIODevice::ReadOnly);//Leer

        //Tener el punto desde donde vamos a ir
        QPoint offset; //Se refiere al deslocamiento o desplazamiento, nombre estandar offset
        dataStream >> offset;//Leer de mi offset

        //Hacia donde vamos a mover
        reina->move(event->pos() - offset);

        //Verificar que todo esta bien y aeptar las cosas
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}
