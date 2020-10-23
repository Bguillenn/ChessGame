#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    setAcceptDrops(true);//Aceptar drops
    BoardIcon.load(":/resources/Icons/tablero-verde.png"); //Cargar el icono del tablero


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

    QByteArray data;
    QDataStream dataStream(&data, QIODevice::WriteOnly);
    dataStream << QPoint(event->pos() - child->pos()); //Encapsular posicion desde se hizo clic

    QMimeData *mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", data);//Encapsulando lo que necesitamos para hacer el drag and drop

    QDrag * drag = new QDrag(this);
    drag->setMimeData(mimeData); //Rescatar informacion al arrastrar el objeto

    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);//Ejecutar drag

}

void Board::dragMoveEvent(QDragMoveEvent *event)
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
    //si es que lo que recibono está érdido
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray data = event->mimeData()->data("application/x-dnditemdata");//Posicion inicial
        QDataStream dataStream(&data, QIODevice::ReadOnly);//Leer

        //Tener el punto desde donde vamos a ir
        QPoint offset; //Se refiere al deslocamiento
        dataStream >> offset;

        //Hacia donde
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
