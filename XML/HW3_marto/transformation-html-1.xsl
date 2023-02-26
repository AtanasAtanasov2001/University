<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Игра</h1>
                <table border="3" align="center">
                    <tr>
                        <th>Заглавие</th>
                        <th>Умение</th>
                        <th>Трудност</th>
                    </tr>
                    <xsl:for-each select="board-game-store/game">
                        <tr>
                            <td>
                                <xsl:call-template name="game-title"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-skill"/>
                            </td>
                            <td>
                                <xsl:call-template name="game-difficulty"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="game-title">
        <xsl:value-of select="title/."/>
    </xsl:template>

    <xsl:template name="game-skill">
        <xsl:value-of select="skill/."/>
    </xsl:template>

    <xsl:template name="game-difficulty">
        <xsl:value-of select="difficulty/@level/."/>
    </xsl:template>

</xsl:stylesheet>