#include "TweetPost.h"

TweetPost::TweetPost(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TweetPost::~TweetPost()
{
}

void TweetPost::on_tweet_clicked()
{

	QString uiTextInput = ui.textEdit->toPlainText();
	std::string postText = uiTextInput.toStdString();
	std::string buffContent;

	XMLParsing p;
	p.load("../date.xml");

	try {
		if (uiTextInput.isEmpty() == true)
			throw 100;
		if (postText.length() > 140)
			throw 101;
	}
	catch (int err) {
		if (err == 100) {
			QMessageBox msgBox;
			int retunred_message = msgBox.warning(this, "Warning!", "Post is empty!", QMessageBox::Ok);

		}
		if (err == 101) {
			QMessageBox msgBox;
			int ret = msgBox.warning(this, "Warning!", "The tweet has more than 140 character, and will only insert that amount.\n "
				"Are you sure you want to make this post ? ", QMessageBox::Yes, QMessageBox::No);
			if (ret == QMessageBox::No)
				return;
			else
				postText = postText.substr(0, 140);
		}
	}
	Tweet post;
	post.SetText(postText);
	post.GetAuthor().SetUsername(p.getUsername());
	post.SetPublishDate(); 
	std::string time = post.timeStringFormat();

	post.SetNoOfDislikes(0);
	post.SetNoOfLikes(0);
	/* declarare obiect de tip comment*/
	std::vector<Comment> CommVector;
	post.SetComments(CommVector);

	p.setAction("Tweet");
	p.setText(postText);
	p.getUsername();
	p.setPublishDate(time);
	p.setNoComments(0);
	p.setNoDislikes(0);
	p.setNoLikes(0);
	p.save("../date.xml");
	
	QMessageBox::information(this, "Tweet", "Tweet created!");
	ui.textEdit->clear();

	TcpSocket socket;
	socket.Connect("127.0.0.1", 27015);
	std::string message = "Tweet";
	socket.Send(message.c_str(), message.size());
	

}