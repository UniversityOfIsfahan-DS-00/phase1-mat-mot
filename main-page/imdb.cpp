#include "imdb.h"
#include "ui_imdb.h"
#include "process-page/process.h"
IMDB::IMDB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMDB)
{
    ui->setupUi(this);
    if (!this->data.load() )
        QMessageBox::information(this , "Load" , "data can't load corectly !! open program again .") ;
    this->setlist() ;
    if (data.my_user.size()==0)
    {
        User tmp  ;
        QString n = "ADMIN" ;
        tmp.setName(n);
        tmp.setHpassword(qHash(n));
        tmp.setUsername(n);
        tmp.setEmail("ADMIN@ADMIN.com");
        data.my_user.push_back(tmp) ;
    }
    //process * tmp = new process () ;
    //tmp->open() ;

}

IMDB::~IMDB()
{
    this->data.save();
    delete ui;
}

const file &IMDB::getData() const
{
    return data;
}

void IMDB::setData(const file &newData)
{
    data = newData;
}

void IMDB::setlist()
{
    ui->title_list->addItems(data.items("move")) ;
}


void IMDB::on_search_box_textChanged(const QString &arg1)
{
    QList<movie_class> tmp = data.mlistcontains(arg1) ;
    ui->title_list->clear() ;
    for (int i=0 ; i<tmp.size() ;i++)
        ui->title_list->addItem(tmp.at(i).getTitle() + " [" +tmp.at(i).getID() + "]") ;
}


void IMDB::on_actionExit_triggered()
{
    this->close() ;
}


void IMDB::on_actionCountact_Us_triggered()
{
    QString tmp ;
    tmp += "Phone number : 09015743537\nAddress : University of Isfahan , Ansar building\n" ;
    tmp += "Telegram ID : @Mat-Mot\nInstgram ID : matin_motmaen\n";
    tmp += "Git repo : https://github.com/mat-mot/ap-final-project.git\nEmail addres : matinmotmaen@gmail.com\n" ;
    tmp += "this program wrriten by mat-mot (*_*)" ;
    QMessageBox::information(this , "Contact Us" , tmp ) ;
}


void IMDB::on_actionSave_Data_triggered()
{
    if (data.save() )
        QMessageBox::information(this , "Save" , "your data seccesfully saved!") ;
}


void IMDB::on_title_list_itemClicked(QListWidgetItem *item)
{
    ui->info_TextEdit->clear() ;
    QString tmp = item->text() ;
    QString tt;
    QStringList tmpp ;
    for (int i=0 ; i<tmp.size() ; i++)
        if (tmp[i]== '[')
        {
            i++ ;
            while (tmp[i]!= ']')
            {
                tt += tmp[i] ;
                i++ ;
            }
        }
    movie_class temp =  data.mlistcontains(tt).at(0) ;
    tmp = "ID :\n" + temp.getID() + "\n";
    tmp += "Ordering :\n" + QString::number( temp.getOrdering()) + "\n";
    tmp += "Title :\n" + temp.getTitle() + "\n";
    tmp += "Region :\n" + temp.getRegion() + "\n";
    tmp += "Language :\n" + temp.getLanguage() + "\n";
    tmp += "Type :\n" ;
    tmpp.clear();
    tmpp = temp.getType() ;
    for (int i=0 ; i<temp.getType().size() ;i++)
        tmp += tmpp.at(i) + "-" ;
    tmp += "Attributes :\n" ;
    tmpp.clear() ;
    tmpp = temp.getAttributes() ;
    for (int i=0 ; i<tmpp.size() ;i++)
        tmp += tmpp.at(i) + "-" ;
    tmp += "is orginal title :\n" + QString::number( temp.getIsorginaltitle()) +"\n" ;
    tmp += "averageRating :\n" + QString::number( temp.getAverageRating()) +"\n" ;
    tmp += "number of votes :\n" + QString::number( temp.getNumvotes()) +"\n" ;
    ui->info_TextEdit->setPlainText(tmp) ;
}


void IMDB::on_actionVote_Movie_triggered()
{
    if (ui->title_list->selectedItems().size()==0)
    {
        QMessageBox::information(this , "vote" , "please select a movie from list first !") ;
        return;
    }
    QString tt , tm = ui->title_list->currentItem()->text() ;
    for (int i=0 ; i<tm.size() ; i++)
        if (tm[i]== '[')
        {
            i++ ;
            while (tm[i]!= ']')
            {
                tt += tm[i] ;
                i++ ;
            }
        }
    if (current_user.getUsername() == "")
    {
        QMessageBox::information(this , "vote" , "please sign in first then vote the movies !") ;
        return;
    }
    if (current_user.containsmovie(tt))
    {
        QMessageBox::information(this , "vote" , "you can vote a movie only once !!") ;
        return;
    }
    process * tmp = new process () ;
    tmp->setChild_d( & this->data) ;
    tmp->setCurrent_movie(data.mlistcontains(tt).at(0));
    tmp->setpos("Vote") ;
    tmp->exec() ;

    this->data.edit_movie(tmp->getCurrent_movie()) ;
    QStringList ttt =  current_user.getVotedlist() ;
    ttt.append(tmp->getCurrent_movie().getID()) ;
    current_user.setVotedlist(ttt) ;
    data.edit_user(current_user) ;
    delete tmp ;
    this->setlist();
}


void IMDB::on_actionLogin_triggered()
{
    process *tmp =new process() ;
    tmp->setChild_d(&data) ;
    tmp->setpos("sign in") ;
    tmp->exec() ;
    current_user = tmp->getCurrent_user() ;
    delete tmp ;
}


void IMDB::on_actionTop_10_triggered()
{
    ui->title_list->clear();
    ui->title_list->setSortingEnabled(false) ;
     QVector<movie_class> tmp =  data.sort_movie();
//     for (int i=0 , j= data.my_imdb_class.size() ; i<data.my_imdb_class.size() && j>=0 ;j-- , i++)
//     {
//        ui->title_list->addItem(QString::number(i+1)+". "+data.my_imdb_class.at(j).getTitle()+ " [" + data.my_imdb_class.at(j).getID()+"]");
//     }
     for (int i=tmp.size()-1 , j=1 ; i>= 0 ; j++ , i--)
         ui->title_list->addItem(QString::number(j) + ". "+tmp.at(i).getTitle()+" [" + tmp.at(i).getID()+"]");
}


void IMDB::on_actionRefresh_triggered()
{
    ui->title_list->clear();
    ui->search_box->clear();
    this->setlist();
    ui->title_list->setSortingEnabled(true) ;
    ui->info_TextEdit->clear();
}

