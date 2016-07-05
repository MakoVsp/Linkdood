import QtQuick 2.0
import com.syberos.basewidgets 2.0

Rectangle{
    id: dyRoot
    color: "white"

    property int columns: dyRoot.width/120
    property int rows: 3
    property int itemsPerPage: columns*rows
    property variant flow: GridView.TopToBottom

    CLine{
        id:line
        anchors.top:parent.top
    }

    GridView{
        id: grid

        width: parent.width
        height: parent.height-2*line.height-20
        anchors.verticalCenter: parent.verticalCenter
//        anchors.fill: parent
//        anchors.topMargin: line.height+5

        model: userDyEmojiManager
        cellHeight: grid.height/rows
        cellWidth: grid.width/columns
        clip: true
        snapMode: GridView.SnapToRow
        flow: dyRoot.flow


        delegate: _testComponent

        onMovementEnded: {
            if(flow === GridView.TopToBottom){
                _centerPageAnimationHorizontal.restart();
                grid.currentIndex = ((grid.width*Math.round(grid.contentX/grid.width))/grid.width)*itemsPerPage;
            console.log("move end:"+grid.currentIndex)
            }
        }
        NumberAnimation { id: _centerPageAnimationHorizontal; target: grid; property: "contentX"; to: (grid.width*Math.round(grid.contentX/grid.width)); duration: 250 }

    }

    Component{
        id: _testComponent
        Item{
            id: _item
            width: grid.cellWidth
            height: grid.cellHeight
            Rectangle{
                id: _rect
                width: grid.cellWidth - 5
                height: grid.cellHeight - 5
                color: "white"
                opacity: mouseCell.pressed ? 0.5: 1;

                anchors.centerIn: _item
                AnimatedImage{
                    id: img
                    source: model.modelData.path
                    width: 64
                    height: width
                    playing:false

                    anchors.top: parent.top
                    anchors.topMargin: 12
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text{
//                    text: qsTr(model.modelData.explain)
                    text:model.modelData.explain
                    onTextChanged: {
                        console.log("explain:"+model.modelData.explain)
                    }

                    font.pixelSize: 24
                    color: "#333333"
                    anchors.top: img.bottom
                    anchors.topMargin: 10
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
            MouseArea{
                id:mouseCell

                anchors.fill: _item
                onClicked: {
                    grid.forceActiveFocus();
                    grid.currentIndex = index;
                    console.log("ddddddddddddddddd:"+_item.width +"h:"+_item.height)
                    //userDyEmojiManager.onBtnItemClicked(""+index);
                   // console.log("ddddddddddddddddd:"+dyRoot.width +"h:"+dyRoot.height)
                }
            }
        }
    }

    Timer{
        id: debounce
        running: false; repeat: false; interval: 300
    }
}
